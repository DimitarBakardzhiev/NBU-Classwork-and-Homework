#include <iostream>

using namespace std;

const char vowels[9] = { 'A', 'E', 'I', 'O', 'U', 'H', 'W', 'Y' };

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

int main()
{

    return 0;
}
