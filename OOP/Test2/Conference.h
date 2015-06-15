#ifndef CONFERENCE_H
#define	CONFERENCE_H

#include "Event.h"

class Conference : public Event {
private:
    string category;
    unsigned sectionsCount, reportsCount;
    double tax;
    
public:
    Conference(unsigned day = 0, unsigned month = 0, unsigned year = 0, 
            string title = "", unsigned invited = 0,
            string category = "", unsigned sectionsCount = 0, 
            unsigned reportsCount = 0, double tax = 0.);

    virtual ostream& inserter(ostream& os) const;
    virtual istream& extractor(istream& is);
};

#endif

