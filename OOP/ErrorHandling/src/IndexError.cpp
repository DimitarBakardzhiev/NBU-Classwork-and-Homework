#include "IndexError.h"
#include <exception>

using namespace std;

IndexError::IndexError(int r, int i)
    : exception(/*"Index:"*/), r(r), i(i)
{
}

ostream& IndexError::rep(ostream & os)
{
    os << "index=" << i << ", must be >=0 and <" << r << endl;
    return os;
}
