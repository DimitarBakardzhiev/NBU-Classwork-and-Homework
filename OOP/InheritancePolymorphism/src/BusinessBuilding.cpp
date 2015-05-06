#include "BusinessBuilding.h"
#include <iostream>

using namespace std;

BusinessBuilding::BusinessBuilding(const string &name, const string &address, double area,
                 double commonArea, int floors, int offices, int storehouses,
                 int workRooms, int workshops)
                 : Building(name,address, area, commonArea, floors)
{
    this->offices = offices;
    this->storehouses = storehouses;
    this->workRooms = workRooms;
    this->workshops = workshops;
}

BusinessBuilding::~BusinessBuilding()
{
}

ostream& BusinessBuilding::ins(ostream &os) const
{
    Building::ins(os);
    os << "Offices: " << this->offices << endl;
    os << "Storehouses: " << this->storehouses << endl;
    os << "Work rooms: " << this->workRooms << endl;
    os << "Workshops: " << this->workshops << endl;

    return os;
}

void BusinessBuilding::usability(ostream &os) const
{
    double usableArea = this->area * (1 - this->commonArea / 100);
    double averageAreaPerOffice =
        (this->offices + (this->storehouses * 2) + (this->workRooms * 6) + (this->workshops * 24)) / usableArea;
    os << "Average office area: " << averageAreaPerOffice << endl;
    os << "Average storehouse area: " << averageAreaPerOffice * 2 << endl;
    os << "Average work room area: " << averageAreaPerOffice * 6 << endl;
    os << "Average workshop area: " << averageAreaPerOffice * 24 << endl;
}
