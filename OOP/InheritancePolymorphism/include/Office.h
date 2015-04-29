#ifndef OFFICE_H
#define OFFICE_H

#include <Building.h>
#include <string>

using std::ostream;
using std::string;

class Office : public Building
{
    private:
        int rooms;

    public:
        Office(const string & name = "", const string &address = "", double area = 0.,
                 double commonArea = 0., int floors = 0, int rooms = 0);
        virtual ~Office();

        ostream& ins(ostream &) const;
        void usability(ostream &) const;
};

ostream& operator<<(ostream &, const Building &);

#endif // OFFICE_H
