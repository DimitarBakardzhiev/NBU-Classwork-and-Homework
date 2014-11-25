#include <iostream>

using namespace std;

int const size = 4;

int main()
{
    int a[size] = { 0, 2, 3, 5 };
    int b[size] = { 9, 7, 8, 4 };
    int result[size + 1] = { 0, 0, 0, 0, 0 };
    int transfer = 0;
    for(int k = size - 1; k >= 0; k--)
    {
        int digitsSum = a[k] + b[k] + transfer;
        result[k + 1] = digitsSum % 10;
        transfer = digitsSum / 10;
    }

    result[0] = transfer;

    return 0;
}
