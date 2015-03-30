#include "BigInteger.h"
#include <string>

using namespace std;

BigInteger::BigInteger()
{
    this->length = 10;
    this->isPositive = true;
    this->value = new int[length];
}

BigInteger::~BigInteger()
{
    delete[] this->value;
}

BigInteger::BigInteger(string number)
{
    this->length = number.length();
    this->isPositive = number[0] == '-' ? false : true;

    if (!this->isPositive)
    {
        this->length--;
    }

    this->value = new int[this->length];
    for (int i = 0; i < this->length; i++)
    {
        if (this->isPositive)
        {
            this->value[i] = number[i] - '0';
        }
        else
        {
            this->value[i] = number[i + 1] - '0';
        }
    }
}

BigInteger::BigInteger(const BigInteger& other)
{
    this->length = other.length;
    this->value = new int[this->length];
    this->isPositive = other.isPositive;

    for (int i = 0; i < this->length; i++)
    {
        this->value[i] = other.value[i];
    }
}

BigInteger& BigInteger::operator=(const BigInteger& other)
{
    if (this != &other)
    {
        delete[] this->value;

        this->length = other.length;
        this->value = new int[this->length];
        this->isPositive = other.isPositive;

        for (int i = 0; i < this->length; i++)
        {
            this->value[i] = other.value[i];
        }
    }

    return *this;
}

int* BigInteger::reverse() const
{
    int* result = new int[this->length];
    int ind = 0;

    for (int i = this->length - 1; i >= 0; i--)
    {
        result[ind] = this->value[i];
        ind++;
    }

    return result;
}

ostream& operator<<(ostream& out, const BigInteger& obj)
{
    if (!obj.isPositive)
    {
        out << "-";
    }

    for (int i = 0; i < obj.length; i ++)
    {
        out << obj.value[i];
    }

    return out;
}

bool BigInteger::operator>(const BigInteger& other) const
{
    if (this->isPositive != other.isPositive)
    {
        return this->isPositive;
    }
    else
    {
        if (this->length != other.length)
        {
            return this->length > other.length;
        }
        else
        {
            for (int i = this->length; i < this->length; i++)
            {
                if (this->value[i] > other.value[i])
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool BigInteger::operator<(const BigInteger& other) const
{
    return !(*this > other);
}

BigInteger BigInteger::operator+(const BigInteger& other) const
{
    if (this->isPositive == other.isPositive)
    {
        int* left = this->reverse();
        int* right = other.reverse();

        int len = this->length > other.length ? this->length : other.length;
        int transfer = 0;
        int current1, current2;
        int* answer = new int[len + 1];

        for (int i = 0; i < len; i++)
        {
            current1 = this->length > other.length ? left[i] : 0;
            current2 = this->length > other.length ? right[i] : 0;
            answer[i] = current1 + current2 + transfer % 10;
            transfer = current1 + current2 + transfer % 10;
        }

        if (transfer)
        {
            answer[len] = transfer;
        }
    }
    else
    {

    }
}
