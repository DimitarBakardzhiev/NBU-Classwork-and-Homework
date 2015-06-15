#ifndef STUDENT_H
#define	STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Student {
private:
    string name;
    int age;
    string specialty;
    double grade;
    
public:
    Student(string name = "", int age = 0, string specialty = "", double grade = 0.);
    
    string getName() const { return this->name; }
    void setName(string name);
    
    int getAge() const { return this->age; }
    void setAge(int age);
    
    string getSpecialty() const { return this->specialty; }
    void setSpecialty(string specialty);
    
    double getGrade() const { return this->grade; }
    void setGrade(double grade);
    
    istream& read(istream& is);
};

#endif

