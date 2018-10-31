#include <stdio.h>
#include <fcntl.h>
#include <bits/fcntl-linux.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <memory.h>

int main() {
    int file = open("ex1.txt", O_RDWR);
    if(file < 0) {
        printf("Error.");
        return (EXIT_FAILURE);
    }

    struct stat mystat = {};
    if (fstat(file ,&mystat)) {
        perror("fstat error");
        return (EXIT_FAILURE);
    }

    off_t size_t = mystat.st_size;

    char* add = mmap(NULL, size_t, PROT_READ|PROT_WRITE, MAP_SHARED,
                   file, 0);

    if (add == MAP_FAILED){
        printf("mmap error\n");
    }

    char* new = "This is a nice day";
    for(int i = 0; i < strlen(new); i++)
    {
        add[i] = new[i];
    }

    for(int i = strlen(new); i < strlen(add); i++) add[i] = ' '; // clean

    return (EXIT_SUCCESS);
}