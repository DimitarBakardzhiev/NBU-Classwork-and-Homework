#include <iostream>
#include <MyString.h>

using namespace std;

int main()
{
    MyString* str = new MyString("gosho");
    MyString a;
    a = str;
    cout << a << endl << str << &str << endl;
    return 0;
}
