#include "RegTasks.h"
#include <cstring>
#include "List.h"

RegTasks::RegTasks(const char* name) :n(0),level(List<int>()), paid(List<double>())
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

RegTasks::RegTasks(const RegTasks &other)
{
    this->copy(other);
}

RegTasks::~RegTasks()
{
    if(n!=0)
    {
        delete[] this->name;
    }
}

RegTasks& RegTasks::operator=(const RegTasks &other)
{
    if (this != &other)
    {
        if (n != 0)
        {
            delete[] this->name;
        }

        this->copy(other);
    }

    return *this;
}

int RegTasks::getN() const
{
    return n;
}

char* RegTasks::getName() const
{
    return this->name;
}

void RegTasks::addTask(int rank, double sum)
 {
    this->n++;
    this->level.add(rank);
    this->paid.add(sum);
 }

double RegTasks::total() const
{
    double sum=0.;
    for(int i=0;i<n;i++) sum += this->paid[i];
    return sum;
}

double RegTasks::average() const
{
    return n==0? 0.: total()/n;
}

int RegTasks::maxPaidRank() const
{
    if(n==0)return -1;
    int ind=0; double max=paid[0];
    for(int i=1;i<n;i++)
        if(paid[i]>max)ind=i,max=paid[i];
    return level[ind];
}

void RegTasks::copy(const RegTasks& other)
{
    this->n = other.n;
    this->level = other.level;
    this->paid = other.paid;
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
}
