#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) x *log10(x) - 1.2
#define df(x) log10(x) + 0.4342
int main()
{
    float x0, f0, x1, f1, e, df0;
    int i = 1, N;
    printf("Enter the value of initial guess x0 : \n ");
    scanf("%f", &x0);
    printf("Enter the value of predefined error e : \n");
    scanf("%f", &e);
    printf("Enter the value of max no. of iterations N : \n");
    scanf("%d", &N);
    printf("\n_____________________________________________________________________________________________________________\n");
    printf("Iteration\tx0\t\t\tf(x0)\t\t\tx1\t\t\tf(x)");
    printf("\n_____________________________________________________________________________________________________________\n");
    do
    {
        f0 = f(x0);
        df0 = df(x0);
        if (df0 == 0)
        {
            printf("Mathematical error ! \n");
            exit(0);
        }
        x1 = x0 - (f0 / df0);
        f1 = f(x1);
        printf("%d\t\t%f\t\t%f\t\t%f\t\t%f\n", i, x0, f0, x1, f1);
        x0 = x1;
        i++;
        if (i > N)
        {
            printf("The solution doesn't converge with %d iterations \n ", N);
            exit(0);
        }
    } while (fabs(f1) > e);
    printf("\n_____________________________________________________________________________________________________________\n");
    printf("The approximate solution is %8f", x1);
    return 0;
}