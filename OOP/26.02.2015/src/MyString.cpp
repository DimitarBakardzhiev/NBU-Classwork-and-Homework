#include "MyString.h"
#include <iostream>

using namespace std;

MyString::MyString(int length)
{
    this->length = length;
    this->str = new char[length + 1];
}

MyString::MyString(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }

    this->length = length;
    this->str = new char[length + 1];
    for (int i = 0; i <= length; i++)
    {
        this->str[i] = str[i];
    }
}

MyString::MyString(const MyString& other)
{
    this->length = other.length;
    this->str = new char[this->length + 1];
    for(int i = 0; i <= this->length; i++)
    {
        this->str[i] = other.str[i];
    }
}

MyString::~MyString()
{
    delete[] this->str;
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        this->length = other.length;
        delete[] this->str;
        this->str = new char[this->length + 1];
        for (int i = 0; i <= this->length; i++)
        {
            this->str[i] = other.str[i];
        }
    }

    return *this;
}

MyString::MyString(MyString& other, bool isMovingConstructor)
{
    this->length = other.length;
    this->str = other.str;
    other.str = NULL;
}

MyString& MyString::operator=(MyString* other)
{
    if (this != other)
    {
        this->length = other->length;
        this->str = other->str;
        other->str = NULL;
    }

    return *this;
}

int MyString::getLength() const
{
    return this->length;
}

const char* MyString::getStr() const
{
    return this->str;
}

MyString MyString::substr(int from, int count) const
{
    if (from < 0 || from > this->length || from + count > this->length)
    {
        return '\0';
    }

    MyString result(count);
    for (int i = 0; i < count; i++)
    {
        result.str[i] = this->str[from + i];
    }

    result.str[count] = '\0';

    return result;
}

ostream& operator<<(ostream& out, const MyString& output)
{
    return out << output.getStr();
}

char MyString::operator[](int position) const
{
    if (position >= 0 && position <= this->length)
    {
        return this->str[position];
    }

    return '\0';
}

MyString MyString::operator+(const MyString& other) const
{
    MyString result(this->length + other.length);
    for (int i = 0; i < this->length; i++)
    {
        result.str[i] = this->str[i];
    }

    for (int i = 0; i <= other.length; i++)
    {
        result.str[i + this->length] = other.str[i];
    }

    return result;
}

MyString& MyString::operator+=(const MyString& other)
{
    char* newStr = new char[this->length + other.length + 1];
    for(int i = 0; i < this->length; i++)
    {
        newStr[i] = this->str[i];
    }

    for(int i = 0; i <= other.length; i++)
    {
        newStr[i + this->length] = other.str[i];
    }

    delete[] this->str;
    this->str = newStr;
    this->length += other.length;

    return *this;
}
