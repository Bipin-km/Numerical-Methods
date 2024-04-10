#include <iostream>
#include <math.h>
#include <iomanip>
#define f(x) 3 * x + sin(x) - exp(x)

using namespace std;

int main()
{
    float x0, x1, x2, f1, f2, f0, e;
    int n, iteration = 0;

    cout << setprecision(8) << fixed;

    cout << "Enter the initial values for x0 and x1: ";
    cin >> x0 >> x1;

    cout << "Enter the error tolerance: ";
    cin >> e;

    cout << "Enter the max number of iterations: ";
    cin >> n;

    cout << "Iterations\t x0\t\t             x1\t\t         x2\t\t       f(x2)\n";
    cout << "-----------------------------------------------------------------------------------------------------\n";

    do
    {

        f0 = f(x0);
        f1 = f(x1);

        if (f0 == f1)
        {
            cout << "Mathematical error";
            return 0;
        }

        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        iteration++;

        if (iteration > n)
        {
            cout << "\nThe solution doesnot converge\n";
            return 0;
        }

        f2 = f(x2);

        cout << iteration << "\t\t " << x0 << "\t\t " << x1 << "\t\t " << x2 << "\t\t " << f2 << "\t\t " << endl;

        x0 = x1;
        x1 = x2;

    } while (fabs(f2) > e);
    cout << "-----------------------------------------------------------------------------------------------------\n";

    cout << "The approximate value for the root is " << x2 << endl;
    return 0;
}