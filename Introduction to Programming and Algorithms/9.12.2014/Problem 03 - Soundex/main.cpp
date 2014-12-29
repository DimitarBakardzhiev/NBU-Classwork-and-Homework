#include <iostream>
#include <cstring>

using namespace std;

bool isVowel(char character)
{
    return character == 'A' || character == 'E' || character == 'I' || character == 'O'
        || character == 'U' || character == 'H' || character == 'W' || character == 'Y';
}

int consonantToCode(char consonant)
{
    if (consonant == 'B' || consonant == 'F'
        || consonant == 'P' || consonant == 'V')
    {
        return 1;
    }
    else if (consonant == 'C' || consonant == 'G' || consonant == 'J'
        || consonant == 'K' || consonant == 'Q' || consonant == 'S'
        || consonant == 'X' || consonant == 'Z')
    {
        return 2;
    }
    else if (consonant == 'D' || consonant == 'T')
    {
        return 3;
    }
    else if (consonant == 'L')
    {
        return 4;
    }
    else if (consonant == 'M' || consonant == 'N')
    {
        return 5;
    }
    else
    {
        return 6;
    }
}

void toUpperCase(char* text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        int asciiCode = (int)text[i];
        if (asciiCode >= 97 && asciiCode <= 122)
        {
            int upperCharCode = asciiCode - 32;
            text[i] = (char)upperCharCode;
        }
    }
}

void fillWithZeroes(char* soundexCode)
{
    for (int i = 1; i < 4; i++)
    {
        if (soundexCode[i] == '\0')
        {
            soundexCode[i] = (char)48;
        }
    }
}

char* soundex(char* name)
{
    toUpperCase(name);

    char* result = new char[5] { '\0' };
    char lastConsonant = '\0';
    for (int i = 0, j = 0; name[i] != '\0'; i++)
    {
        if (i == 0)
        {
            result[j] = name[i];
            j++;
            lastConsonant = name[i];
        }
        else
        {
            if (name[i] == lastConsonant || isVowel(name[i]))
            {
                continue;
            }
            else if (j > 3)
            {
                break;
            }
            else
            {
                int code = consonantToCode(name[i]);
                result[j] = (char)(code + '\0');
                j++;
                lastConsonant = name[i];
            }
        }
    }

    fillWithZeroes(result);

    return result;
}

int main()
{
    char* code = soundex("ROBERT");
    for (int i = 0; i < 4; i++)
    {
        cout << code[i];
    }

    cout << endl;
    return 0;
}
