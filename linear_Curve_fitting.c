#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
    clock_t start, end;
    start = clock();
    int i, n;
    double x[50], y[50], sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0, a, b;

    printf("\nlinear curve fitting method of least square\n");

    printf("Enter the no of data points(n):");
    scanf("%d", &n);

    printf("Enter the values of x and y: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    printf("\nThe table of data that you enter as follow\n");
    for (i = 0; i < n; i++)
    {
        printf("%lf %lf\n", x[i], y[i]);
    }

    // Computing sums
    for (i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    // Calculating the slope and intercept
    b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / n;
    printf("\n The values of a and b are : a = %.15lf & b = %.15lf", a, b);

    printf("\nThe line is Y = %.15lf + %.15lf X\n", a, b);

    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time: %f seconds\n", cpu_time_used);
    return 0;
}
