#include "Hotel.h"

Hotel::Hotel(const string & name, const string &address, double area,
                 double commonArea, int floors, int rooms, int apartments)
                 : Office(name, address, area, commonArea, floors, rooms)
{
    this->apartments = apartments;
}

Hotel::~Hotel()
{
}
