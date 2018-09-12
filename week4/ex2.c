#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#define loop 3

int main(){
    for(int i = 0; i < loop; i++)
    {
        fork();
    }
    sleep(5);
    return 0;
}
