#include <stdio.h>
#include <stdlib.h>

#define n 5
#define m 3

int main() {
    FILE * f = fopen("input_dl.txt", "r");
    int e[m], a[m];
    for(int i = 0; i < m; i++)
    {
        fscanf(f, "%1d", &e[i]);
    }
    for(int i = 0; i < m; i++)
    {
        fscanf(f, "%1d", &a[i]);
    }
    int c[n][m], r[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) fscanf(f, "%1d", &c[i][j]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) fscanf(f, "%1d", &r[i][j]);
    }

    int deadlock = 0;
    int* mark = (int*) calloc(n, sizeof(int));
    for(int loop = 0; loop < n; loop++)
    {
        int one_chosen = 0;
        for(int i = 0; i < n; i++)
        {
            if(mark[i]) continue;
            int can_run = 1;
            for(int j = 0; j < m; j++)
            {
                if(c[i][j] + a[j] < r[i][j])
                {
                    can_run = 0;
                    break;
                }
            }
            if(can_run)
            {
                mark[i] = 1;
                one_chosen = 1;
                for(int j = 0; j < m; j++)
                {
                    a[j] += c[i][j];
                    c[i][j] = 0;
                }
                break;
            }
        }
        if(!one_chosen) deadlock = 1;
    }
    FILE * o = fopen("output_dl.txt", "w");
    if(deadlock)
    {
        fprintf(o, "Deadlocked processes:\n");
        for(int i = 0; i < n; i++)
        {
            if(!mark[i]) fprintf(o, "Process %d\n", i + 1);
        }
    }
    else fprintf(o, "No deadlock is detected.\n");
    fclose(f);
    return 0;
}