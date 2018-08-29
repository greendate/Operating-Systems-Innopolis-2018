#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main()
{
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("INT size: %d value: %d\n", sizeof(int), a);
    printf("FLOAT size: %d value: %f\n", sizeof(float), b);
    printf("DOUBLE size: %d value: %lf\n", sizeof(double), c);
    return 0;
}
