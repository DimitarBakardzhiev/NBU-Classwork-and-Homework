#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

using namespace std;

class MyString
{
    private:
        char* str;
        int length;

    public:
        MyString(int = 0);
        MyString(const char*);
        MyString(const MyString&);
        ~MyString();
        MyString& operator=(const MyString&);
        MyString(MyString&, bool);      // преместващ конструктор
        MyString& operator=(MyString*); // преместващо присвояване

        int getLength() const;
        const char* getStr() const;

        MyString substr(int, int) const;
        char operator[](int) const;
        MyString operator+(const MyString&) const;
        MyString& operator+=(const MyString&);
};

ostream& operator<<(ostream&, const MyString&);

#endif // MYSTRING_H
