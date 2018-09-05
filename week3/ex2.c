#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int d = *a;
    *a = *b;
    *b = d;
}

void bubble_sort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int* p = a; p < a + n; p++)
        {
            if(*p > *(p + 1)) swap(p, p + 1);
        }
    }
}

int main()
{
    int a[7] = {64, 34, 25, 12, 22, 11, 90};
    bubble_sort(a, 7);
    for(int i = 0; i < 7; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
