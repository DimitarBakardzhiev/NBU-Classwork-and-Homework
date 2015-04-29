#ifndef REPEATEDIN_H
#define REPEATEDIN_H

class RepeatedIn{
    char c[1000];

public:
    RepeatedIn& operator>>(int&);
    RepeatedIn& operator>>(unsigned&);
    RepeatedIn& operator>>(double&);
};

#endif // REPEATEDIN_H
