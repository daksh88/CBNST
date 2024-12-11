// To implement Newton forward interpolation method

#include <stdio.h>
#include <stdlib.h>

int fact(int x)
{
    int f = 1;
    for(int i = 1; i <= x; i++)
        f = f * i;
        return f;
}

int main()
{ 
    // Reading the number of argumnets
    int n;
    printf("Enter the number of arguments: ");
    scanf("%d", &n);

    // Reading x and y
    float arr[n][n+1];
    for(int i = 0; i < n; i++)
    {
        printf("Enter x%d and y%d (space separated): ", i, i);
        scanf("%f%f", &arr[i][0], &arr[i][1]);
    }

    // Creating the forward difference matrix
    for(int i = 2; i < n+1; i++)
    {
        for(int j = 0; j < n-i+1; j++)
        {
            arr[j][i] = arr[j+1][i-1] - arr[j][i-1];
        }
    }

    // printing the difference matrix
    printf("\n\nThe forward difference table is: \n\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i+1; j++)
        {
            printf("%0.2f   ", arr[i][j]);
        }
        printf("\n");
    }

    // Reading the interpolation point
    float x;
    printf("\nEnter a point of interpolation: ");
    scanf("%f", &x);

    float h = arr[1][0] - arr[0][0];
    float u = (x - arr[0][0]) / h;

    float result = arr[0][1];
    float t = 1.0;

    for(int i = 0; i < n-1; i++)
    {
        t = t * (u-i);
        result += (t * arr[0][i+2]) / fact(i+1);
    }

    printf("The value of y at x = %0.2f is: %0.2f\n", x, result);

    return 0;

}