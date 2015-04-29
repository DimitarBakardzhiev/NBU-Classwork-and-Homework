#ifndef INDEXERROR_H
#define INDEXERROR_H

#include <iostream>
#include <exception>

using namespace std;

class IndexError : public exception {
	int r,i;

public:
	IndexError(int r,int i);
	ostream& rep(ostream & os);
};

#endif
