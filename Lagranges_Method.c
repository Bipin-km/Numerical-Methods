#include <stdio.h>
#include <conio.h>

void main()
{
    float x[100], y[100], xp, yp = 0, p;
    int i, j, n;
    /* Input Section */
    printf("Enter the number of terms of the table: ");
    scanf("%d", &n);
    printf("Enter the respective values of x & y:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
    /* Printing the table */
    printf("\n The table you entered is as follows:\n");
    for (i = 0; i < n; i++)
    {
        printf("%.3f\t%.3f\n", x[i], y[i]);
    }
    printf("Enter interpolation point: ");
    scanf("%f", &xp);
    /* Implementing Lagrange Interpolation */
    for (i = 1; i <= n; i++)
    {
        p = 1;
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + p * y[i];
    }
    printf("\n f(%f) = %f", xp, yp);
}
