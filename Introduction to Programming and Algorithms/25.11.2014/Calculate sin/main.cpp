#include <iostream>
#include <cmath>

using namespace std;

double Fact(int number)
{
    if(number == 0 && number == 1)
    {
        return 1;
    }
    else
    {
        double result = 1;
        for(int i = 2; i <= number; i++)
        {
            result *= i;
        }

        return result;
    }
}

double lastFact = 1;

double EfficientFact(int number, int lastCalculatedFact)
{
    if(number == 0 && number == 1)
    {
        return 1;
    }
    else
    {
        for(int i = lastCalculatedFact + 1; i <= number; i++)
        {
            lastFact *= i;
        }

        return lastFact;
    }
}

int main()
{
    double sin = 0;
    int sign = 1;
    double x;
    cin >> x;
    int lastCalculated = 1;
    for(int i = 1; i < 1000; i += 2)
    {
        sin += pow(x, i) / EfficientFact(i, lastCalculated) * sign;
        sign *= -1;
        if(i > 1)
        {
            lastCalculated += 2;
        }
    }

    cout << sin << endl;

    return 0;
}
