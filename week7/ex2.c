#include <stdio.h>
#include <malloc.h>

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    int *a = calloc(n, sizeof(int));
    for(int i = 1; i < n; i++) a[i] = a[i - 1] + 1;
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return (0);
}