#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <stdlib.h>
#include <signal.h>

void sigterm_func(int nmr)
{
    if (nmr == SIGTERM)
        printf("SIGTERM!\n");
}

int main() {


    pid_t  pid = fork();

    if(pid == -1)
    {
        printf("fork Error");
        exit(1);
    }

    if(pid > 0)
    {
        sleep(10);
        if(signal(SIGTERM, sigterm_func) == SIG_ERR)
            printf("\nNO SIGKILL\n");
    }
    else
    {
        while(1)
        {
            printf("I'm alive!");
            sleep(10);
        }
    }



    return 0;
}