#include <iostream>

using namespace std;

int main()
{
    int sign = 1;
    double sum = 0;
    for(int i = 1; i < 10000000; i += 2)
    {
        sum += (double)1 / i * sign;
        sign *= -1;
    }

    cout << sum * 4 << endl;
    return 0;
}
