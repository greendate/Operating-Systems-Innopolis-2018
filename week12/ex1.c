#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>

int main() {

    FILE * f = fopen("/dev/random", "r");
    FILE * out = fopen("ex1.txt", "w+");
    char s[20];
    fgets(&s, 20, f);
    for(int i = 0; i < 20; i++) fprintf(out, "%c", s[i]);
    return 0;
}