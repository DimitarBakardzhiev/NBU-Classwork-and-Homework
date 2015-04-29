#ifndef BUILDING_H
#define BUILDING_H

#include <string>

using std::ostream;
using std::string;

class Building
{
    private:
        string name;
        string address;
        int floors;

    protected:
        double area;
        double commonArea;

    public:
        Building(const string & name = "", const string &address = "", double area = 0.,
                 double commonArea = 0., int floors = 0);
        virtual ~Building();

        virtual ostream& ins(ostream &) const;
        virtual void usability(ostream &) const;
};

#endif // BUILDING_H
