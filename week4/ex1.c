#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    int n = 24;
    pid_t pid;


       pid = fork();

        if(pid == 0)
        {
            printf("Hello from parent [%d - %d]\n", pid, n);
            exit(0);
        }
        else printf("Hello from child [%d - %d]\n", pid, n);

    return 0;
}
