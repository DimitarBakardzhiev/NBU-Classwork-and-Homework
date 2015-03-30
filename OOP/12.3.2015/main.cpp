#include <iostream>
#include <BigInteger.h>

using namespace std;

int main()
{
    BigInteger a("-1"), b(a), c("123456"), d;
    d = c;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    cout << BigInteger("1") + BigInteger("111");
    return 0;
}
