// To implement Newton Backward interpolation method

#include <stdio.h>
#include <math.h>
float fact(int i, float p)
{
    float ans = p;
    for (int j = i; j > 1; j--)
    {
        ans = ans * (p - 1 + j);
    }
    return ans;
}
float factorial(int j)
{
    float ans = 1;
    for (int i = 1; i <= j; i++)
        ans *= i;
    return ans;
}
int main()
{
    int n;
    printf("Enter the number of arguments: ");
    scanf("%d", &n);

    float x[n];
    float y[n]; 
    for (int i = 0; i < n; i++)
    {
        printf("Enter x%d and y%d (space separated): ", i, i);
        scanf("%f", &x[i]);
        scanf("%f", &y[i]);
    }

    float num;
    printf("\nEnter a point of interpolation: ");
    scanf("%f", &num);


    float p = (float)(num - x[n - 1]) / (float)(x[1] - x[0]);
    float ans = y[n - 1];
    
    printf("\n");
    for (int i = 1; i < n; i++)
    {
        float new_y[n - i];
        printf("d^%dy: ", i);
        for (int j = 0; j < n - i; j++)
        {
            new_y[j] = y[j + 1] - y[j];
            printf("%.2f ", new_y[j]);
        }
        printf("\n");
        ans += (fact(i, p) / factorial(i)) * new_y[n - i - 1];
        for (int h = 0; h < n - i; h++)
        {
            y[h] = new_y[h];
        }
        y[n - i] = '\0';
    }
    printf("The value of y at x = %0.2f is: %0.2f\n", num, ans);
}