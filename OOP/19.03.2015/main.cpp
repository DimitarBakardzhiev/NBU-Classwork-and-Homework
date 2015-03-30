#include <iostream>
#include <Set.h>

using namespace std;

int main()
{
    Set a;
    a.add_elem(2);
    a.add_elem(3);
    a.add_elem(3);
    a.add_elem(4);
    a.add_elem(4);

    Set b;
    b.add_elem(3);
    b.add_elem(4);
    b.add_elem(5);

    cout << a + b;

    return 0;
}
