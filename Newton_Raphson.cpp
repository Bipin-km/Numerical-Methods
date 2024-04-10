#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>

#define f(x) x *log(x) - 1.2
#define g(x) log(x) + 1

using namespace std;

int main()
{
    float x0, x1, f0, f1, g0, e;
    int count = 1, N;

    cout << setprecision(6) << fixed;

    /* Inputs */
    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter tolerable error: ";
    cin >> e;
    cout << "Enter maximum iteration: ";
    cin >> N;

    /* Implementing Newton Raphson Method */
    cout << "------------------------------------------------------------------------\n";
    cout << "Iterations\tx0\t\t\x1\t\t\tf(x)" << endl;
    cout << "------------------------------------------------------------------------\n";
    do
    {
        g0 = g(x0);
        f0 = f(x0);
        if (g0 == 0)
        {
            cout << "Mathematical Error.";
            exit(0);
        }

        x1 = x0 - f0 / g0;

        cout << count << "\t\t" << x0 << "\t\t" << x1 << "\t\t" << f0 << endl;

        x0 = x1;
        count = count + 1;

        if (count > N)
        {
            cout << "Not Convergent.";
            exit(0);
        }

        f1 = f(x1);

    } while (fabs(f1) > e);

    cout << "Required root is: " << x1;
    return 0;
}