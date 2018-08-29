#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    int empty = n - 1;
    int stars = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < empty; j++) printf(" ");
        for(int j = 0; j < stars; j++) printf("*");
        printf("\n");
        empty--;
        stars += 2;
    }
    return 0;
}
