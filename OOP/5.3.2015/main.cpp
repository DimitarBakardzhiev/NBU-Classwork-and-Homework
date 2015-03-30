#include <iostream>
#include <RegTasks.h>
#include <stdlib.h>
#include <cstring>
#include "List.h"

using namespace std;

void report(const RegTasks &p)
{
    cout<<"Records: "<<p.getN()<<"\n\tTotal paid: "<<p.total()<<endl;
    cout<<"\tAverage paid: "<< p.average()<<endl;
    cout<<"\tMax paid task of rank: "<<p.maxPaidRank()<<endl;
    cout<<"\tEmployee: "<<p.getName()<<endl;
}

int main()
{
    for(int k=0;k<20;k++){
        cout<<endl;
        char* newName = new char[6];
        strcpy(newName, "Ivan");
        newName[4] = (char)(k + 65);
        newName[5] = '\0';
        RegTasks x(newName);
        report(x);
        for(int i=0;i<10;i++)
            x.addTask(1+rand()%10, 1.25+rand()%2000);
        report(x);
    }

    return 0;
}
