#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
    string filePath;
    cout << "Enter file path";
    cin >> filePath;

    ifstream file(filePath, ios::in | ios::binary);
    if (!file)
    {
        cerr << "File could not be opened" << endl;
        return 1;
    }

    ostringstream data;
    data << file.rdbuf();

    return 0;
}
