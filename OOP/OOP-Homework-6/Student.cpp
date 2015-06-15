#include "Student.h"

Student::Student(string name, int age, string specialty, double grade) {
    try {
        this->setName(name);
        this->setAge(age);
        this->setSpecialty(specialty);
        this->setGrade(grade);
    } catch(string err) {
        cerr << err << endl;
    } catch(...) {
        cerr << "Failed to initialize object!" << endl;
    }
}

void Student::setName(string name) {
    if (name.length() > 50) {
        throw "Name length cannot be more than 50 symbols!";
    }

    this->name = name;
}

void Student::setAge(int age) {
    if (age < 0) {
        throw "Age cannot be negative!";
    }
    
    this->age = age;
}

void Student::setSpecialty(string specialty) {
    if (specialty.length() > 100) {
        throw "Specialty length cannot be more than 100 symbols!";
    }

    this->specialty = specialty;
}

void Student::setGrade(double grade) {
    if (grade < 0) {
        throw "Grade cannot be negative!";
    }

    this->grade = grade;
}

istream& Student::read(istream& is) {
    string name, specialty;
    int age;
    double grade;
    is >> name >> age >> specialty >> grade;
    try {
        this->setName(name);
        this->setAge(age);
        this->setSpecialty(specialty);
        this->setGrade(grade);
    } catch(string err) {
        cerr << err << endl;
    } catch(...) {
        cerr << "Failed to initialize object!" << endl;
    }
    
    return is;
}