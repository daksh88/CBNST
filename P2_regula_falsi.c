// To find real roots of the equation using Regula-Falsi method

#include <stdio.h>
#include <math.h>

#define func(x) (x * log10(x) - 1.20)

int main()
{
    float x0, x1, x2 = 0, temp, f0, f1, f2, e;
    int iteration = 1;

    while(1)
    {
        printf("Enter the initial range: ");
        scanf("%f%f", &x0, &x1);

        printf("Enter the tolerable error: ");
        scanf("%f", &e);
        
        if(func(x0) * func(x1) <= 0.0)
            break;
        else
            printf("\nIncorrect Range\n");        
    }
    printf("Iteration \t x0 \t\t\t x1 \t\t\t x2 \t\t\t f(x2)");
    do
    {
        temp = x2;

        f0 = func(x0);
        f1 = func(x1);
        
        x2 = (x0 * f1 - x1 * f0)  / (f1 - f0);

        f2 = func(x2);

        printf("\n%d \t\t %f \t\t %f \t\t %f \t\t %f", iteration, x0, x1, x2, f2);

        if(f2 == 0)
            break;
        else if(f0 * f2 < 0)
            x1 = x2;
        else
            x0 = x2;


        iteration = iteration + 1;
    } while (fabs(x2 - temp) > e);

    printf("\nThe Root is : %f\n", x2);

    return 0;
}