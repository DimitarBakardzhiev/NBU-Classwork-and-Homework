#include "Money.h"

using namespace std;

Money::Money()
{
    this->levs = 0;
    this->stotinki = 0;
}

Money::Money(int levs, int stotinki)
{
    this->setLevs(levs);
    this->setStotinki(stotinki);
}

Money::~Money()
{
}

Money::Money(const Money& other)
{
    this->levs = other.levs;
    this->stotinki = other.stotinki;
}

Money& Money::operator=(const Money& other)
{
    if (this != &other)
    {
        this->levs = other.levs;
        this->stotinki = other.stotinki;
    }

    return *this;
}

int Money::getLevs() const
{
    return this->levs;
}

void Money::setLevs(int levs)
{
    this->levs = levs;
}

int Money::getStotinki() const
{
    return this->stotinki;
}

void Money::setStotinki(int stotinki)
{
    this->stotinki = stotinki;

    if (this->stotinki >= 100)
    {
        this->levs += this->stotinki / 100;
        this->stotinki %= 100;
    }

    if (this->stotinki < 0)
    {
        this->stotinki *= -1;
        this->levs -= 1;

        if (this->stotinki >= 100)
        {
            this->levs -= this->stotinki / 100;
            this->stotinki %= 100;
        }

        this->stotinki = 100 - this->stotinki;
    }
}

ostream& operator<<(ostream& os, const Money& obj)
{
    cout << obj.levs << "," << obj.stotinki;
    return os;
}

istream& operator>>(istream& is, Money& obj)
{
    int levs, stotinki;
    is >> levs;
    is >> stotinki;

    obj.setLevs(levs);
    obj.setStotinki(stotinki);

    return is;
}

Money Money::operator+(const Money& other) const
{
    Money result(this->levs + other.levs, this->stotinki + other.stotinki);

    return result;
}

Money Money::operator-(const Money& other) const
{
    Money negativeOther(-other.levs, -other.stotinki);

    return *this + negativeOther;
}
