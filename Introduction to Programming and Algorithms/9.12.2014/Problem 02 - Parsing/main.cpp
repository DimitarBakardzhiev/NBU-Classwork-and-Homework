#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int charToInt(char digit)
{
    int asciiCode = (int)digit;
    return (int)(asciiCode - 48);
}

int stringToNumber(char* number)
{
    int result = 0;
    // number[strlen(number)] == '\0' !!!!
    for (int i = strlen(number) - 1, digits = 0; i >= 0; i--, digits++)
    {
        int currentDigit = charToInt(number[i]);
        result += currentDigit * pow(10, digits);
    }

    return result;
}

int countDigits(int number)
{
    int count = 0;
    do
    {
        number /= 10;
        count++;
    } while(number != 0);

    return count;
}

char digitToChar(int digit)
{
    char result = (char)(digit + 48);
    return result;
}

void numberToString(int number, char str[])
{
    int digitsCount = countDigits(number);
    for (int i = digitsCount - 1; i >= 0; i--)
    {
        int currentDigit = number % 10;
        str[i] = digitToChar(currentDigit);
        number /= 10;
    }
}

int main()
{
//    char number[10];
//    cin >> number;
//    int numberAsInt = stringToNumber(number);
//    cout << numberAsInt << endl;

    int number = 10;
    char* str = new char[countDigits(number) + 1];
    numberToString(number, str);
    cout << str;
    return 0;
}
