#ifndef REGISTRATION_H
#define	REGISTRATION_H

#include "Conference.h"

class Registration : public Conference {
private:
    string reportTitle;
    string reportCategory;
    
public:
    Registration(unsigned day = 0, unsigned month = 0, unsigned year = 0, 
            string title = "", unsigned invited = 0,
            string category = "", unsigned sectionsCount = 0, 
            unsigned reportsCount = 0, double tax = 0.,
            string reportTitle = "", string reportCategory = "");
    
    virtual ostream& inserter(ostream& os) const;
    virtual istream& extractor(istream& is);
};

#endif

