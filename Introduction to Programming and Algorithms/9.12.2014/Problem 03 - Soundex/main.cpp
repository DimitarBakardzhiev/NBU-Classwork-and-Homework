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

char* toUpperCase(char* text)
{
    char* result = new char[strlen(text) + 1];
    for (int i = 0; text[i] != '\0'; i++)
    {
        int asciiCode = (int)text[i];
        if (asciiCode >= 97 && asciiCode <= 122)
        {
            asciiCode = asciiCode - 32;
        }

        result[i] = (char)asciiCode;
    }

    return result;
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
    name = toUpperCase(name);

    char* result = new char[5] { '\0' };
    char lastConsonant = '\0';
    bool vowelBetweenConsonants = false;
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
            if (name[i] == lastConsonant || isVowel(name[i])
                || (consonantToCode(name[i]) == consonantToCode(lastConsonant) && vowelBetweenConsonants == false))
            {
                if (isVowel(name[i]))
                {
                    vowelBetweenConsonants = true;
                }

                continue;
            }
            else if (j > 3)
            {
                break;
            }
            else
            {
                int code = consonantToCode(name[i]);
                result[j] = (char)(code + 48);
                j++;
                lastConsonant = name[i];
                vowelBetweenConsonants = false;
            }
        }
    }

    fillWithZeroes(result);

    return result;
}

int main()
{
    char* code = soundex("Tymczak");
    for (int i = 0; i < 4; i++)
    {
        cout << code[i];
    }

    cout << endl;
    return 0;
}
