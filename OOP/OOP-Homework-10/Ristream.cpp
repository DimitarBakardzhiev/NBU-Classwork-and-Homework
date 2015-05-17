#include "Ristream.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Ristream::Ristream(int l, bool w):len(l),wsp(w) {

}

Ristream& Ristream::operator >> (int & v){
    v = rint();
    return * this;
}

Ristream& Ristream::operator >> (double & v){
    v = rdbl();
    return * this;
}

Ristream& Ristream::operator >> (unsigned & v){
    v = rand();
    return * this;
}

Ristream& Ristream::operator >> (char * v){
    rstr(v);
    cout << v<<endl;
    return * this;
}

int Ristream::rint(){
    int t = rand();
    return (t%2==0)?t:-t;
}

double Ristream::rdbl(){
    int t = rint();
    double d = ((double)rand()/RAND_MAX)*100.;
    return t*d;
}

void Ristream::rstr(char * v){
    char b[] = "abcdefghijklmnopqrstuvwxyz ";
    for (int i = 0; i < len-1; i++)
    {   
        v[i] = (wsp)?b[rand()%27]:b[rand()%26];
    }
    v[len-1] = '\0';
}