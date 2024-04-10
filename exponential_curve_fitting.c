#include <stdio.h>
#include <math.h>

#define MAX_DATA_POINTS 100

// Function to fit the exponential curve
void fitExponentialCurve(double x[], double y[], int n, double *a, double *b)
{
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++)
    {
        printf("| %.6lf | %.6lf |\n", x[i], y[i]);
        sumX += x[i];
        sumY += log(y[i]);
        sumXY += x[i] * log(y[i]);
        sumX2 += x[i] * x[i];
    }

    double denominator = (n * sumX2) - (sumX * sumX);
    *a = exp((sumY * sumX2 - sumX * sumXY) / denominator);
    *b = (n * sumXY - sumX * sumY) / denominator;
}

int main()
{
    double x[MAX_DATA_POINTS], y[MAX_DATA_POINTS];
    int n;
    printf("\nFitting of y=ae^(bx) using the method of least square\n");
    printf("Enter the no. of data points: ");
    scanf("%d", &n);

    printf("Enter respective values of x & y:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    printf("\n The table you entered is as follows:\n");
    printf("\n____________________________________________________\n");
    printf("|   x   \t|\t   y   |\n");
    printf("____________________________________________________\n");

    double a, b;
    fitExponentialCurve(x, y, n, &a, &b);

    printf("The  required exponential curve for fitting is\n y = %.5lf * e^(%.5lf * x)\n", a, b);

    return 0;
}