// To implement Gauss elimination method

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k;
    float a[100][101] = {0};
    printf("Enter the number of equations: ");
    scanf("%d", &n);
    int idx = 0;
    int xyz = 0;
    while (n--)
    {
        char s[200];
        printf("Enter the equation:\n");
        scanf("%s", s);
        bool flag = false;
        int num = 0;
        int cont = 0;
        int sign = 1;
        for (int i = 0; i < strlen(s); i++)
        {
            if (flag && (s[i] >= '0' && s[i] <= '9'))
            {
                cont = cont * 10 + (s[i] - '0');
            }
            if (s[i] == '=')
                flag = true;
            else if (s[i] == '-')
                sign = -1;
            else if (s[i] == 'x')
            {
                if (sign == -1 && num == 0)
                {
                    num = 1;
                }
                a[idx][0] = sign * num == 0 ? 1 : sign * num;
                num = 0;
                xyz++;
                sign = 1;
            }
            else if (s[i] == 'y')
            {
                if (sign == -1 && num == 0)
                {
                    num = 1;
                }
                a[idx][1] = sign * num == 0 ? 1 : sign * num;
                num = 0;

                if (xyz == 0)
                    a[idx][0] = 0;
                xyz++;
                sign = 1;
            }
            else if (s[i] == 'z')
            {
                if (sign == -1 && num == 0)
                {
                    num = 1;
                }
                a[idx][2] = sign * num == 0 ? 1 : sign * num;
                num = 0;
                if (xyz == 0)
                {
                    a[idx][0] = 0;
                    a[idx][1] = 0;
                }
                if (xyz == 1)
                {
                    if (a[idx][1] == '\0')
                        a[idx][1] = 0;
                    else
                        a[idx][0] = 0;
                }
                sign = 1;
                xyz++;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
        }
        a[idx][3] = sign * cont;
        idx++;
    }
    float t;
    printf("Equation 1: (%.0f)x+(%.0f)y+(%.0f)z=%.0f\n", a[0][0], a[0][1], a[0][2], a[0][3]);
    printf("Equation 2: (%.0f)x+(%.0f)y+(%.0f)z=%.0f\n", a[1][0], a[1][1], a[1][2], a[1][3]);
    printf("Equation 3: (%.0f)x+(%.0f)y+(%.0f)z=%.0f\n", a[2][0], a[2][1], a[2][2], a[2][3]);
    printf("\n\n");
    printf("Augmented Matrix: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%.2f ", a[i][j]);
        }
        printf(" \n");
    }
    printf("\n");
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i > j)
            {
                t = a[i][j] / a[j][j];
                for (k = 0; k < 4; k++)
                {
                    a[i][k] = a[i][k] - t * a[j][k];
                }
            }
        }
    }
    printf("Final Matrix form : \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("\t %.2f", a[i][j]);
        }
        printf("\n");
    }
    n = 2;
    float sum = 0.0;
    float x[n];
    x[n] = a[n][n + 1] / a[n][n];
    for (i = n - 1; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j <= n; j++)
        {
            sum = sum + a[i][j] * x[j];
        }
        x[i] = (a[i][n + 1] - sum) / a[i][i];
    }
    printf("\n\nValues are :\n");

    for (i = 0; i <= n; i++)
    {
        printf("x%d = %.2f\n", i, x[i]);
    }
}