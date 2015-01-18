#include <iostream>

using namespace std;

int preCondition(int a, int b)
{
    int r = a % b;
    while (r > 0)
    {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int postCondition(int a, int b)
{
    int r;
    do
    {
        r = a % b;
        a = b;
        b = r;
    } while(r > 0);

    return a;
}

int withLabels(int a, int b)
{
    int r = a % b;
    condition:
    if (r > 0)
    {
        a = b;
        b = r;
        r = a % b;
    }

    if (r > 0)
    {
        goto condition;
    }

    return b;
}

int main()
{
    cout << preCondition(1071, 462) << endl;
    cout << postCondition(1071, 462) << endl;
    cout << withLabels(1071, 462) << endl;
    return 0;
}
