#ifndef HOTEL_H
#define HOTEL_H

#include <Office.h>


class Hotel : public Office
{
    private:
        int apartments;

    public:
        Hotel(const string & name = "", const string &address = "", double area = 0.,
                 double commonArea = 0., int floors = 0, int rooms = 0, int apartments = 0);
        virtual ~Hotel();
        Hotel(const Hotel& other);
        Hotel& operator=(const Hotel& other);
};

#endif // HOTEL_H
