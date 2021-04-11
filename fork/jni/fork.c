/*****************************************************************************
File name: test.c
Description: 
    This file implements another test. It generates a process and output my
    student ID with the PID of the process. Then it will also generate its 
    child process, and output my student ID with the PID of the child process.
    In the child process, it will execl `testARM` built from 'test.c' to call 
    the 'ptree' system call.
Author: ADSWT518
Version: 1.0
Date: 2021.4.10
*****************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("This is a test for project 1, fork and execute the test of ptree:\n\n");

    pid_t pid;
    pid = fork();
    if (pid < 0)
    { /* error occurred */
        printf("Fork Failed\n");
        return 1;
    }
    else if (pid == 0)
    { /* child process */
        pid_t childPid = getpid();
        printf("519021910804 child pid: %d\n", childPid);
        execl("/data/misc/cs356/testARM", "testARM", NULL);
        // 注意，这里第一个参数是可执行文件的完整路径（包括文件本身），第二个参数不知道是啥qwq感觉没有也行啊但是没有就不会输出任何东西orz
    }
    else
    { /* parent process */
        wait(NULL);
        pid_t parentPid = getpid();
        printf("519021910804 parent pid: %d\n", parentPid);
        // printf("Child Complete\n");
    }

    // printf("Test End!\n\n");
    return 0;
}