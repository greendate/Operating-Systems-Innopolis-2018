#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#define N 5
#define M 9

void* my_realloc(void* r, size_t size);

int main() {

    int *a = malloc(N * sizeof(int));

    for(int i = 0; i < N; i++)
    {
        if(i == 0) a[i] = 1;
        else a[i] = a[i - 1] + 1;
        printf("%d ", a[i]);
    }
    printf("\n");

    my_realloc(a, M * sizeof(int));
    for(int i = 0; i < M; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void* my_realloc(void* r, size_t size)
{
    if(size == 0)
    {
        free(r);
        return r;
    }
    if(r == NULL)
    {
        r = malloc(size);
        return r;
    }

    void* a = malloc(sizeof(r));
    memcpy(a, r, sizeof(r));
    r = malloc(size);
    memcpy(r, a, sizeof(a));
    free(a);
    return r;
}
