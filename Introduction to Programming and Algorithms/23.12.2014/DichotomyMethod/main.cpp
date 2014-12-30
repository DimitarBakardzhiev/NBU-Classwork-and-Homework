#include <iostream>
#include <cmath>

using namespace std;

double expression(double x)
{
    return x * x * x + 3 * x - 5;
    // return exp(x) - 2 * x - 2;
}

void recursiveDichotomy(double a, double b, double minimumDistance)
{
    if (!(a < b || (expression(a) < 0 && expression(b) > 0) || (expression(a) > 0 && expression(b) < 0)))
    {
        cout << "Invalid input!" << endl;
        return;
    }

    double c = (a + b) / 2;
    double expressionValue = expression(c);
    if (expressionValue == 0 || abs(expressionValue) < abs(minimumDistance))
    {
        cout << "Root found: " << c << endl;
        return;
    }
    else if (expressionValue * expression(a) > 0)
    {
        recursiveDichotomy(c, b, minimumDistance);
    }
    else
    {
        recursiveDichotomy(a, c, minimumDistance);
    }
}

void dichotomy(double a, double b, double minimumDistance, int maxIterations)
{
    if (!(a < b || (expression(a) < 0 && expression(b) > 0) || (expression(a) > 0 && expression(b) < 0)))
    {
        cout << "Invalid input!" << endl;
        return;
    }

    bool foundRoot = false;
    for (int i = 0; i < maxIterations; i++)
    {
        double c = (a + b) / 2;
        double expressionValue = expression(c);
        if (expressionValue == 0 || abs(expressionValue) < abs(minimumDistance))
        {
            cout << "Root found: " << c << endl;
            foundRoot = true;
            return;
        }
        else if (expressionValue * expression(a) > 0)
        {
            a = c;
        }
        else
        {
            b = c;
        }
    }

    if (foundRoot == false)
    {
        cout << "No roots found!" << endl;
    }
}

int main()
{
    dichotomy(-101, 101, 0.000001, 1000000);
    recursiveDichotomy(-101, 101, 0.000001);
    return 0;
}
