#ifndef BUSINESSBUILDING_H
#define BUSINESSBUILDING_H

#include <Building.h>


class BusinessBuilding : public Building
{
    private:
        int offices;
        int storehouses;
        int workRooms;
        int workshops;

    public:
        BusinessBuilding(const string & = "", const string & = "", double = 0.,
                 double = 0., int = 0, int = 0, int = 0, int = 0, int = 0);
        virtual ~BusinessBuilding();

        virtual ostream& ins(ostream &) const;
        virtual void usability(ostream &) const;
};

#endif // BUSINESSBUILDING_H
