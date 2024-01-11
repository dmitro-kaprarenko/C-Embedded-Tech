#include <stdio.h>
#include <math.h>

// Calculate z1
double z1(double a)
{
    return (1 - 2 * sin(a) * sin(a)) / (1 + sin(2 * a));
}

// Calculate z2
double z2(double a)
{
    return (1 - tan(a)) / (1 + tan(a));
}

int main()
{
    double a;

    // Input the value of angle alpha
    printf("Enter the value of angle alpha in radians: ");
    scanf("%lf", &a);

    // Output the results
    printf("z1(a) = %.4lf\n", z1(a));
    printf("z2(a) = %.4lf\n", z2(a));

    return 0;
}