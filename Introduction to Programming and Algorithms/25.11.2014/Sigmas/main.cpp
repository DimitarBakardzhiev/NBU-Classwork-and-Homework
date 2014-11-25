#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int n;
    cin >> n;
    for(int i = 2; i < n; i++)
    {
        sum += i * i - 2 * i;
    }

    cout << sum << endl;
    return 0;
}
