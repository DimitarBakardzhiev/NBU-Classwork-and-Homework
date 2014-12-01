#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x;
    cin >> x;
    double sin = 0;

    double numerator = x;
    long long denominator = 1;
    int sign = 1;
    for (int i = 1; i <= 66; i += 2)
    {
        if (i != 1)
        {
            numerator *= x * x;
            denominator *= (i - 1) * i;
        }

        sin += (numerator / denominator) * sign;
        sign *= -1;
    }


    cout << sin << endl;

    return 0;
}
