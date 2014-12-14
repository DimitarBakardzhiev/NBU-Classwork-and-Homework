#include <iostream>

using namespace std;

bool isValidNumber(unsigned number, int sum, int difference)
{
    unsigned rightDigit = number % 10;
    unsigned leftDigit = (number / 10) % 10;

    unsigned reversedNumber = rightDigit * 10 + leftDigit;

    bool sumCondition = rightDigit + leftDigit == sum;
    bool differenceCondition = reversedNumber - number == difference;

    return sumCondition && differenceCondition;
}

void findNumber(unsigned number, int sum, int difference)
{
    if (isValidNumber(number, sum, difference))
    {
        return;
    }

    if (number > 99)
    {
        return;
    }

    findNumber(number + 1, sum, difference);
}

int startNumber = 0;

int main()
{
    cout << "Input A + B: ";
    int sum;
    cin >> sum;

    cout << "Input BA - AB: ";
    int difference;
    cin >> difference;

    findNumber(startNumber, sum, difference);
    cout << startNumber;

    return 0;
}
