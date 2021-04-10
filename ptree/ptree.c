#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/unistd.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
MODULE_LICENSE("Dual BSD/GPL");

#define __NR_hellocall 356

#define maxBufferSize 1000
#define notExistFlag 0

static int (*oldcall)(void);

struct printfo
{
    pid_t parent_pid;       /* process id of parent, set 0 if it has no parent*/
    pid_t pid;              /* process id */
    pid_t first_child_pid;  /* pid of youngest child, set 0 if it has no child */
    pid_t next_sibling_pid; /* pid of older sibling, set 0 if it has no sibling*/
    long state;             /* current state of process */
    long uid;               /* user id of process owner */
    char comm[64];          /* name of program executed */
    int generation;         /* generation of the process, set 0 if the process is root process  */
};

void storeInfo(struct task_struct *task, struct printfo *p, int generation)
{
    // 注意判断各种可能的情况！
    if (task != &init_task)
    {
        // 注意这里不能用task->parent!=NULL，因为init_task的parent并非空指针，而是指向它自己！
        // 具体参见linux kernel v5.11.12 的 /init/init_task.c#L107
        p->parent_pid = task->parent->pid;

        if (task->sibling.next != &(task->parent->children))
        {
            // 判断依据：当一个进程没有下一个兄弟进程时，它的sibling.next会指向父进程的children成员
            p->next_sibling_pid = list_entry(task->sibling.next, struct task_struct, sibling)->pid;
            // 这里next_sibling_pid记录的是它自己的next sibling，而不是第一个子进程的next sibling
        }
        else
        {
            p->next_sibling_pid = notExistFlag;
        }
    }
    else
    {
        p->parent_pid = notExistFlag;
        p->next_sibling_pid = notExistFlag; // 没有parent则不可能有sibling
    }

    if (!list_empty(&task->children))
    {
        p->first_child_pid = list_entry(task->children.next, struct task_struct, sibling)->pid;
    }
    else
    {
        p->first_child_pid = notExistFlag;
    }

    p->pid = task->pid;
    p->state = task->state;
    p->uid = task->real_cred->uid;
    strcpy(p->comm, task->comm);
    p->generation = generation;
}

void dfs(struct task_struct *task, struct printfo *buf, int *nr, int generation)
{
    struct task_struct *chd_task; // the task_struct where chd is located
    struct list_head *chd;        // the sibling part of task's child processes

    storeInfo(task, &buf[*nr], generation);

    ++(*nr);

    list_for_each(chd, &task->children)
    {
        chd_task = list_entry(chd, struct task_struct, sibling);
        // 之所以是sibling，是因为task->children->next是指向的第一个子进程的sibling成员
        // 所以整个循环是在以第一个子进程的sibling为头结点的双链表中进行的
        // 获得的chd也都是task的子进程们的sibling
        // 而list_entry的第三个参数表示第一个参数在其宿主结构体中的身份
        // printk(KERN_INFO "pid:%d, task_name:%s\n", chd_task->pid, chd_task->comm);

        dfs(chd_task, buf, nr, generation + 1);
    }
}

static int ptree(struct printfo *buf, int *nr)
{
    // nr不能写成引用是因为c语言没有引用。。。我傻了

    struct printfo *buf_in_kernel = (struct printfo *)kmalloc(sizeof(struct printfo) * maxBufferSize, GFP_KERNEL);
    // !!!这里要在内核空间也申请内存，因为buf是在用户空间中的，而内存空间和用户空间不能互相访问

    int nr_in_kernel = 0;

    if (buf_in_kernel == NULL)
    {
        printk(KERN_ALERT "memory allocation failed!\n");
        return 1;
    }
    printk(KERN_ALERT "entry secceed!");

    read_lock(&tasklist_lock);
    dfs(&init_task, buf_in_kernel, &nr_in_kernel, 0);
    read_unlock(&tasklist_lock);

    // 把buf_in_kernel中的数据拷贝到buf中
    if (copy_to_user(buf, buf_in_kernel, sizeof(struct printfo) * maxBufferSize) || copy_to_user(nr, &nr_in_kernel, sizeof(int)))
    {
        printk(KERN_ALERT "copy failed!");
        kfree(buf_in_kernel);
        return 1;
    }

    kfree(buf_in_kernel);
    return 0;
}

static int addsyscall_init(void)
{
    long *syscall = (long *)0xc000d8c4;
    oldcall = (int (*)(void))(syscall[__NR_hellocall]);
    syscall[__NR_hellocall] = (unsigned long)ptree;
    printk(KERN_INFO "module load!\n");
    return 0;
}

static void addsyscall_exit(void)
{
    long *syscall = (long *)0xc000d8c4;
    syscall[__NR_hellocall] = (unsigned long)oldcall;
    printk(KERN_INFO "module exit!\n");
}

module_init(addsyscall_init);
module_exit(addsyscall_exit);