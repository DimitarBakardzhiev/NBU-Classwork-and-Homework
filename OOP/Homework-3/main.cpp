#include <iostream>
#include <Employee.h>
#include <Programmer.h>

using namespace std;

int main()
{
    cout << Programmer("gosho", 1500) << endl;
    cout << Employee("pesho", 0) << endl;

    return 0;
}
