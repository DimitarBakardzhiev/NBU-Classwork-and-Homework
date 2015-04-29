#include "Building.h"
#include <iostream>

using namespace std;

Building::Building(const string & name, const string &address, double area,
                 double commonArea, int floors)
{
    this->name = name;
    this->address = address;
    this->area = area;
    this->commonArea = commonArea;
    this->floors = floors;
}

Building::~Building()
{
}

ostream& Building::ins(ostream &out) const
{
    out << "Name: " << this->name << endl;
    out << "Address: " << this->address << endl;
    out << "Area: " << this->area << endl;
    out << "Floors: " << this->floors << endl;

    return out;
}

void Building::usability(ostream & out) const
{
    out << "Usable area: " << this->area * (1 - this->commonArea / 100) << endl;
}
