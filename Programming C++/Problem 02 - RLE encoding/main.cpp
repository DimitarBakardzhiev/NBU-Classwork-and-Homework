#include <iostream>
#include <cstring>

using namespace std;

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

char* numberToString(int number)
{
    int digitsCount = countDigits(number);
    char* str = new char[digitsCount + 1];
    for (int i = digitsCount - 1; i >= 0; i--)
    {
        int currentDigit = number % 10;
        str[i] = digitToChar(currentDigit);
        number /= 10;
    }

    str[digitsCount] = '\0';
    return str;
}

char* encodeRLE(char* password)
{
    int passwordLength = strlen(password);
    char* encoded = new char[passwordLength + 1] { '\0' };
    unsigned count = 0;
    for (int i = 0; i < passwordLength; i++)
    {
        if (password[i] == password[i + 1])
        {
            if (count == 0)
            {
                count = 2;
            }
            else
            {
                count ++;
            }
        }
        else
        {
            if (count == 0)
            {
                const char* currentChar = new char[2] { password[i], '\0' };
                encoded = strcat(encoded, currentChar);
            }
            else
            {
                const char* currentChar = new char[2] { password[i], '\0' };
                int digits = countDigits(count);
                char* number = new char[digits + 1];
                strcpy(number, numberToString(count));
                number[digits] = '\0';
                encoded = strcat(encoded, strcat(number, currentChar));
                count = 0;
            }
        }
    }

    encoded[passwordLength] = '\0';
    return encoded;
}

int main()
{
    cout << encodeRLE("AASSSvvrwwq");
    return 0;
}
