#include "Conference.h"

Conference::Conference(unsigned day, unsigned month, unsigned year, 
            string title, unsigned invited,
        string category, unsigned sectionsCount, 
            unsigned reportsCount, double tax)
    : Event(day, month, year, title, invited), category(category),
    sectionsCount(sectionsCount), reportsCount(reportsCount), tax(tax) {
}

ostream& Conference::inserter(ostream& os) const {
    Event::inserter(os);
    return os << category << sectionsCount << reportsCount << tax;
}

istream& Conference::extractor(istream& is) {
    Event::extractor(is);
    return is >> category >> sectionsCount >> reportsCount >> tax;
}