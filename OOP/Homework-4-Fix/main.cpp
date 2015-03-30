#include <iostream>
#include <Employee.h>
#include <Manager.h>
#include <Executive.h>

using namespace std;

int main()
{
    Employee gosho("gosho", 1500, 3);
    Manager pesho("pesho", 3000, 15, "IT");

    /*Employee* e = &pesho;
    cout << *e;
    // Manager* m = dynamic_cast<Manager*>(&gosho);
    Manager* m = (Manager*)&gosho;
    cout << *m;*/

    Executive goshko("Goshko", 14000, 10, "IT");
    Executive peshko = goshko;
    cout << peshko;

    return 0;
}
