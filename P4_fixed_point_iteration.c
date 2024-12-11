// To find real roots of the equation using Fixed Point Iteration method

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define   f(x)   (2 * x - log10(x) - 7)
#define   g(x)   ((log10(x) + 7) / 2)

int main()
{
	float x0, x1, e;
    int step = 1, N;

    printf("Enter the initial guess: ");
    scanf("%f", &x0);

    printf("Enter tolerable error: ");
    scanf("%f", &e);

    printf("Enter maximum iteration: ");
    scanf("%d", &N);

    printf("\nStep \t\t x0 \t\t f(x0) \t\t x1 \t\t f(x1)\n");
    do
	{
        x1 = g(x0);
        printf("\n%d \t\t %f \t %f \t %f \t %f ", step, x0, f(x0), x1, f(x1));
		step = step + 1;
		
        if(step > N)
        {
            printf("Not Convergent.");
            exit(0);
        }
          
		x0 = x1;
		  
	} while(fabs(f(x1)) > e);
	 
	printf("\n\nThe Root is: %f\n", x1);
	
	return(0);
}