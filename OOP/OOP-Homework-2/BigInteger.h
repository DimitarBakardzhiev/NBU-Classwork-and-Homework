#ifndef _BIGINTEGER_H
#define _BIGINTEGER_H

#include <iostream>
#include <string>

class BigInteger{
    friend std::ostream& operator << (std::ostream&, const BigInteger &);
    int * reverse() const;
public:
    BigInteger();
    BigInteger(std::string);
    BigInteger(const BigInteger &);
    ~BigInteger();
    BigInteger& operator=(const BigInteger &);
    BigInteger operator+(const BigInteger &) const;
	BigInteger operator-(const BigInteger &) const;
    bool operator >(const BigInteger &)const;
    bool operator <(const BigInteger &)const;
    int getN()const;
    void setN(int);
	bool abs_max(const BigInteger &)const;
private:
    int n;
    int * val;
    bool pos;
};

std::ostream& operator << (std::ostream&, const BigInteger &);

#endif