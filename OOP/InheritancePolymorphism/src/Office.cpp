#include "Office.h"
#include <Building.h>
#include <iostream>

using namespace std;

Office::Office(const string & name, const string &address, double area,
                 double commonArea, int floors, int rooms)
                 : Building(name, address, area, commonArea, floors)
{
    this->rooms = rooms;
}

Office::~Office()
{
}

ostream& Office::ins(ostream &out) const
{
    Building::ins(out);
    out << "Rooms: " << rooms << endl;

    return out;
}

void Office::usability(ostream &out) const
{
    out << "Area per room: " << (this->area * (1 - this->commonArea / 100)) / rooms << endl;
}

ostream& operator<<(ostream &out, const Building &obj)
{
    return obj.ins(out);
}
