#include<stdio.h>
#include<math.h>
#define f(x) exp(x) - 3*x 


int main(){

    float x0 , x1 , x2 , f0 , f1, f2 , e; 
    int iteration = 0 ;

    printf("Enter the tolerance (e):");
    scanf("%f", &e);

    Input:
    printf("Enter the value of lower and upper initial guesses x0 and x1:\n");
    scanf("%f",&x0);
    scanf("%f",&x1);

    f0 = f(x0) ; 
    f1 = f(x1);

    if(f0 * f1 > 0){
        printf("Wrong initial guesses\n");
        goto Input;
    }

    printf("\n----------------------------------------------------------------------------------------\n");
    printf("\nIteration\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    printf("\n----------------------------------------------------------------------------------------\n");



    do{
        x2 = (x0 + x1)/2.0;
        f2= f(x2);

        printf("\n%d\t\t    %f\t     %f\t     %f\t    %f\n",iteration , x0, x1 , x2 , f2);

        if(f0 * f2 < 0){
            x1 = x2 ; 
            f1 = f2;
        }
        else{
            x0 = x2;
            f0 = f2;
        }


        iteration++;
    }while( fabs(f2) > e );
    printf("\n-------------------------------------------------------------------------------------\n");

    printf("\nThe required approx root is:%.8f",x2);


    return 0;
}