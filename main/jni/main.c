#include <stdio.h>
#include <stdlib.h>

#define maxBufferSize 1000

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

int main()
{
    printf("This is a test for project 1:\n\n");

    struct printfo *buffer;

    int nr = 0;

    buffer = (struct printfo *)malloc(sizeof(struct printfo) * maxBufferSize);
    printf("memory allocation secceed!\n");

    if (buffer == NULL)
        exit(1);

    syscall(356, buffer, &nr);
    printf("system call secceed!\n");

    int i, j;
    for (i = 0; i < nr; ++i)
    {
        struct printfo p = buffer[i];

        for (j = 0; j < buffer[i].generation; ++j)
        {
            printf("\t");
        }
        printf("%s,%d,%ld,%d,%d,%d,%ld\n", p.comm, p.pid, p.state, p.parent_pid, p.first_child_pid, p.next_sibling_pid, p.uid);
    }

    printf("Test End!\n\n");
    free(buffer);

    return 0;
}