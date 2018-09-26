#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <wait.h>
#include <stdlib.h>
#include <signal.h>

void sigterm_func(int nmr)
{
    if (nmr == SIGTERM)
        printf("SIGTERM!\n");
}

int main() {

    int fd[2], state;
    pipe(fd);

    pid_t  pid = fork(), retrieve, cpid, temp;

    if(pid == -1)
    {
        printf("fork Error");
        exit(1);
    }

    if(pid == 0)
    {
        printf("1st child. ID => %d\n", getpid());
        sleep(10);
        read(fd[0], retrieve, sizeof(retrieve));
        kill(retrieve, SIGSTOP);
    }

    if (cpid == 0) {
        sleep(10);
        printf("2nd child. ID => %d\n", getpid());
    } else {
        write(fd[1], temp, sizeof(temp)+1);
        waitpid(cpid, &state, 0);
    }
    close(fd[0]);
    close(fd[1]);

    return 0;
}