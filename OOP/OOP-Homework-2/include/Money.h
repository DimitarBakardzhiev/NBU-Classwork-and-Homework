#ifndef MONEY_H
#define MONEY_H
#include <iostream>

using namespace std;

class Money
{
    private:
        int levs;
        int stotinki;
    public:
        Money();
        Money(int, int);
        ~Money();
        Money(const Money&);
        Money& operator=(const Money&);

        int getLevs() const;
        void setLevs(int);
        int getStotinki() const;
        void setStotinki(int);

        friend ostream& operator<<(ostream&, const Money&);
        friend istream& operator>>(istream&, Money&);

        Money operator+(const Money&) const;
        Money operator-(const Money&) const;
};

#endif // MONEY_H
