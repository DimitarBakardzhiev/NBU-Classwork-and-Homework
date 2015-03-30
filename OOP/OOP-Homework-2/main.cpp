#include <iostream>
#include <Money.h>

using namespace std;

int main()
{
    Money a(5, 20), b(6, 40), c(2, 80);
    cout << Money(2, 20) - Money(3, 20);
    return 0;
}
