#include "DblArr.h"
#include <iostream>
#include <IndexError.h>
#include <assert.h>

using namespace std;

DblArr::DblArr(int n)
{
    r = new double[n];
    sz = n;
    for (int i = 0; i < n; i++)
    {
        r[i]=0.;
    }
}

DblArr::DblArr(const DblArr& a)
{
    r = new double[a.sz];
    sz = a.sz;
    for (int i = 0; i < sz; i++)
    {
        r[i]=a.r[i];
    }
}

DblArr& DblArr::operator=(const DblArr & a)
{
    if(this != &a)
    {
        delete []r;
        r = new double[a.sz];
        sz = a.sz;
        for (int i = 0; i < sz; i++)
        {
            r[i]=a.r[i];
        }
    }

    return *this;
}

double& DblArr::operator[](int i) const
{
    /*if(i < 0 || i >= sz)
    {
    //Изпълнението не може да продължи с връщане на
    //адрес от масива, защото ще се фалшифицира изпълнението
    //на функцията, която използва масива.
    //Изхвърля се изключение.
    //Тук може да се докладват локалните стойности, но за
    //илюстрация те се предават по-нагоре чрез обект.
        cerr << "class DblArr [] exception.\n";
        throw IndexError(sz, i);
    }*/
    assert(!(i < 0 || i >= sz));

    return r[i];
}

ostream& DblArr::ins(ostream & os) const
{
    os << "[";
    for(int j = 0; j < sz-1; j++)
    {
        os << r[j]<< ", ";
    }

    return os << r[sz-1] << "]" << endl;
}

ostream& operator<<(ostream& os, const DblArr& ia) {
	return ia.ins(os);
}
