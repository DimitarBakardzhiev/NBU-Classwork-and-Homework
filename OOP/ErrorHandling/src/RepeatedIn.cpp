#include "RepeatedIn.h"
#include <iostream>

using namespace std;

RepeatedIn& RepeatedIn::operator>>(int & i)
{
    for(cin>>i;cin.fail();
		    cin.clear(),cin.getline(c,999),
		    cout<<"Try again:",cin>>i);
	    return *this;
}

RepeatedIn& RepeatedIn::operator>>(unsigned & i)
{
    for(cin>>i;cin.fail();
		    cin.clear(),cin.getline(c,999),
		    cout<<"Try again:",cin>>i);
	    return *this;
}

RepeatedIn& RepeatedIn::operator>>(double & d)
{
    for(cin>>d;cin.fail();
		    cin.clear(),cin.getline(c,999),
		    cout<<"Try again:",cin>>d);
	    return *this;
}
