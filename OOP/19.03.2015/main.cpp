#include <iostream>
#include <Set.h>
#include <SortedSet.h>

using namespace std;

int main()
{
    SortedSet a;
    a.add_elem(4);
    a.add_elem(3);
    a.add_elem(3);
    a.add_elem(4);
    a.add_elem(2);

    SortedSet b;
    b.add_elem(5);
    b.add_elem(4);
    b.add_elem(3);

    cout << a;

    return 0;
}
