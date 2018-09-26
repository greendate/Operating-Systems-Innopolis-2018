#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    int fd1[2];
    int fd2[2];

    char fixed_str[] = "admin";
    char input_str[] = "";
    pid_t p;

    if (pipe(fd1)==-1 || pipe(fd2)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }

    p = fork();

    if (p < 0)
    {
        fprintf(stderr, "fork Failed" );
        return 1;
    }
    else if (p > 0)
    {

        close(fd1[0]);


        write(fd1[1], input_str, strlen(input_str)+1);
        close(fd1[1]);

        wait(NULL);

        close(fd2[1]);

        read(fd2[0], input_str,  100);
        printf("New string: %s\n", input_str);
        close(fd2[0]);
    }

    else
    {
        close(fd1[1]);

        read(fd1[0], input_str, 100);

        int k = 0;
        int i;
        for (i=0; i<strlen(fixed_str); i++)
            input_str[k++] = fixed_str[i];

        input_str[k] = '\0';

        close(fd1[0]);
        close(fd2[0]);

        write(fd2[1], input_str, strlen(input_str)+1);
        close(fd2[1]);

        exit(0);
    }
}