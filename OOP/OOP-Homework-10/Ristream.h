#ifndef RISTREAM_H
#define	RISTREAM_H

class Ristream{
public:
    Ristream(int =20, bool =true);
    Ristream& operator >> (int & v);
    Ristream& operator >> (double & v);
    Ristream& operator >> (unsigned & v);
    Ristream& operator >> (char * v);
private:
    int rint();
    double rdbl();
    void rstr(char * v);

    int len;
    bool wsp;
};

#endif