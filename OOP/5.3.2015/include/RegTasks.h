#ifndef REGTASKS_H
#define REGTASKS_H
#include "List.h"

using namespace std;

class RegTasks
{
    int n;
    List<int> level;
    List<double> paid;
    char* name;

    void copy(const RegTasks&);
public:
    RegTasks(const char* = "No name");
    RegTasks(const RegTasks&);
    ~RegTasks();
    RegTasks& operator=(const RegTasks&);
    int getN()const;
    char* getName() const;
    void addTask(int, double);
    double total()const;
    double average()const;
    int maxPaidRank()const;
};

#endif // REGTASKS_H
