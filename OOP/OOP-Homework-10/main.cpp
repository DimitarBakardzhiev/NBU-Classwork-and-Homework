#include <cstdlib>
#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include "Ristream.h"
#include <fstream>

using namespace std;

int main() {

    int size = 6;
    Employee **employees = new Employee*[size];
    Ristream ri;
    
    unsigned id;
    unsigned age;
    unsigned experience;
    double salary;
    char* qualification = new char[21];
    char* name = new char[21];
    
    char* department = new char[21];
    unsigned employeesCount;
    
    for (int i = 0; i < size; i++) {
        ri >> id >> age >> experience >> salary >> qualification >> name;
        if (i % 2 == 1) {
            ri >> department >> employeesCount;
            employees[i] = new Manager(id, string(name), age, experience, salary,
                    string(qualification), string(department), employeesCount);
        }

        employees[i] = new Employee(id, string(name), age, 
                experience, salary, string(qualification));
    }
    
    ofstream fileWriter("Employees.txt");
    if (!fileWriter) {
        cerr << "Failed to create text file!" << endl;
    }

    for (int i = 0; i < size; i++) {
        fileWriter << employees[i] << endl;
    }
    
    fileWriter.close();
    
    ofstream binaryFileWriter("Employees.bin", ios::binary);
    if (!binaryFileWriter) {
        cerr << "Failed to create binary file!" << endl;
    }
    
    for (int i = 0; i < size; i++) {
        binaryFileWriter.write((char*)employees[i], sizeof(employees[i]));
    }
    
    binaryFileWriter.close();
    
    ifstream binaryFileReader("Employees.bin", ios::binary);
    if (!binaryFileReader) {
        cerr << "Failed to open binary file!" << endl;
    }

    Employee *youngest, *mostExperienced, *highestPaid;
    for (int i = 0; i < size; i++) {
        binaryFileReader.read((char*)employees[i], sizeof(employees[i]));
    }
    
    youngest = getYoungest(employees, size);
    mostExperienced = getMostExperienced(employees, size);
    highestPaid = getHighestPaid(employees, size);
    
    binaryFileReader.close();
    
    ofstream reportWriter("Report.txt");
    if (!reportWriter) {
        cerr << "Failed to create a report!" << endl;
    }

    reportWriter << "Youngest employee: " << endl;
    reportWriter << *youngest << endl;
    reportWriter << "Most experienced employee: " << endl;
    reportWriter << *mostExperienced << endl;
    reportWriter << "Highest paid employee: " << endl;
    reportWriter << *highestPaid << endl;
    
    reportWriter.close();
    
    return 0;
}

