#include <iostream>

using namespace std;

void ToUpperCase(char* text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        int asciiCode = (int)text[i];
        if (asciiCode >= 97 && asciiCode <= 122)
        {
            text[i] = (char)(asciiCode - 32);
        }
    }
}

int main()
{
    char text[255];
    cin >> text;
    ToUpperCase(text);
    cout << text << endl;
    return 0;
}
