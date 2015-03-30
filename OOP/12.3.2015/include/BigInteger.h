#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <iostream>
#include <string>

using namespace std;

class BigInteger
{
    private:
        int* value;
        bool isPositive;
        int length;

        int* reverse() const;

    public:
        BigInteger();
        BigInteger(string);
        BigInteger(const BigInteger&);
        virtual ~BigInteger();
        BigInteger& operator=(const BigInteger&);
        BigInteger operator+(const BigInteger&) const;
        bool operator>(const BigInteger&) const;
        bool operator<(const BigInteger&) const;

        int getLength() const;
        void setLength(int);

        friend ostream& operator<<(ostream&, const BigInteger&);
};

ostream& operator<<(ostream&, const BigInteger&);

#endif // BIGINTEGER_H
