#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    int file1 = open("ex1.txt", O_RDONLY);

    size_t size = lseek(file1, 0, SEEK_END);

    char *src = mmap(NULL, size, PROT_READ, MAP_PRIVATE,  file1, 0);

    int file2 = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);

    ftruncate(file2, size);

    char* dest = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, file2, 0);

    memcpy(dest, src, size);

    munmap(src, size);
    munmap(dest, size);

    close(file1);
    close(file2);

    return 0;
}