#include <iostream>

using namespace std;

double expression(double x)
{
    return x * x * x + 3 * x - 5;
}

double scanningMethod(double a, double b, double stepSize)
{
    while (a + stepSize <= b)
    {
        double leftStep = expression(a);
        double rightStep = expression(a + stepSize);
        if (leftStep * rightStep < 0)
        {
            break;
        }

        a += stepSize;
    }

    return (a + a + stepSize) / 2;
}

int main()
{
    cout << scanningMethod(1, 1.5, 0.000001);
    return 0;
}
