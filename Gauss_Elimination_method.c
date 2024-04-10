#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k;
    float a[30][30], x[30], sum = 0, ratio = 0;
    /* Gauss Elimination Method*/
    printf("\n Gauss Elimination method \n");
    /*Input*/
    printf("Enter the size of the coefficient matrix A(i.e the no. of unknown variables) (n) : \n");
    scanf("%d", &n);
    printf("\n Enter the values of elements a[i][j] of the augmented matrix [A:C] \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= (n + 1); j++)
        {
            printf("a[%d][%d] = \t", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    /* failure case of Gauss*/
    for (i = 1; i <= n - 1; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf(" \nMathematical Error!! Please interchange the rows & check again \n");
            exit(0);
        }
    }
    /* Apply Forward Elimination and transform into upper triangular form*/
    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= n; i++)
        {
            if (i > j)
            {
                ratio = a[i][j] / a[j][j];
                for (k = 1; k <= n + 1; k++)
                {
                    a[i][k] = a[i][k] - ratio * a[j][k];
                }
            }
        }
    }
    /*Check conditions for solutions*/
    if (a[n][n] == 0.0 && a[n][n + 1] == 0.0)
    {
        printf("The system is consistent and has infinite solutions \n");
        exit(0);
    }
    if (a[n][n] == 0.0 && a[n][n + 1] != 0.0)
    {
        printf("The system is inconsistent and has no solutions \n");
        exit(0);
    }
    /*Apply Backward substitution method*/
    x[n] = a[n][n + 1] / a[n][n];
    for (i = n - 1; i > 0; i--)
    {
        sum = 0.0;
        for (j = i + 1; j <= n; j++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n + 1] - sum) / a[i][i];
    }
    printf("\nThe system is consistent and has  unique solution : \n");
    for (i = 1; i <= n; i++)
    {
        printf("\t\t x[%d] = %.6f\n", i, x[i]);
    }
    return 0;
}