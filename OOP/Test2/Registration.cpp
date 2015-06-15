#include "Registration.h"

Registration::Registration(unsigned day, unsigned month, unsigned year, 
            string title, unsigned invited,
        string category, unsigned sectionsCount, 
            unsigned reportsCount, double tax,
        string reportTitle, string reportCategory) 
    : Conference(day, month, year, title, invited, category, sectionsCount, reportsCount, tax),
    reportTitle(reportTitle), reportCategory(reportCategory) {
}

ostream& Registration::inserter(ostream& os) const {
    Conference::inserter(os);
    return os << reportTitle << reportCategory;
}

istream& Registration::extractor(istream& is) {
    Conference::extractor(is);
    return is >> reportTitle >> reportCategory;
}