#include <stdio.h>
#include <conio.h>
#include <math.h>

/* Define function here */
#define f(x) 1 / (1 + x * x)

int main()
{
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;
    /* Input */
    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);
    printf("Enter number of sub intervals: ");
    scanf("%d", &subInterval);

    /* Calculation */
    /* Finding step size */
    stepSize = (upper - lower) / subInterval;

    /* Finding Integration Value */
    integration = f(lower) + f(upper);
    for (i = 1; i <= subInterval - 1; i++)
    {
        k = lower + i * stepSize;
        integration += (i % 3 == 0) ? 2 * f(k) : 3 * f(k);
    }
    /* Display f(x) in each sub-interval */
    printf("\n\n Y values in each subinterval: \n");
    for (i = 0; i <= subInterval; i++)
    {
        k = lower + i * stepSize;
        printf("f(%.3f) = %.3f\n", k, f(k));
    }

    integration = integration * stepSize * 3 / 8;
    printf("\nRequired value of integration is: %.3f", integration);
    return 0;
}