#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/unistd.h>
MODULE_LICENSE("Dual BSD/GPL");

#define __NR_hellocall 356

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

void storeInfo(struct task_struct *task, struct printfo* p, int generation)
{
    (*p).parent_pid = task->parent->pid;
    (*p).pid = task->pid;
    (*p).first_child_pid = list_entry(task->children.next, struct task_struct, sibling)->pid;
    (*p).next_sibling_pid = list_entry(task->children.next->next, struct task_struct, sibling)->pid;
    (*p).state = task->state;
    (*p).uid = task->real_cred->uid;
    strcpy((*p).comm, task->comm);
    (*p).generation = generation;
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

        dfs(chd_task, buf, nr, ++generation);
    }
}

static int ptree(struct printfo *buf, int *nr)
{
    // nr不能写成引用是因为c语言没有引用。。。我傻了
    dfs(&init_task, buf, nr, 0);
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