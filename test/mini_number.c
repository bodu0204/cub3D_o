# include <float.h>
#include <stdio.h>
#include <math.h>

int main()
{
    double d = 1.0 - 0.000000000000001;
    printf("%lf, %f\n",d, floor(d));
}