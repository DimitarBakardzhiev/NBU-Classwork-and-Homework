#ifndef DBLARR_H
#define DBLARR_H

#include <iostream>

using namespace std;

class DblArr {
protected:
	int sz;
	double *r;

public:
	DblArr(int n=1);
	DblArr(const DblArr& a);
	DblArr& operator=(const DblArr & a);

	virtual ~DblArr() { delete []r; }

	double& operator[](int i)const;
	ostream& ins(ostream & os)const;
};

ostream& operator<<(ostream& os, const DblArr& ia);

#endif
