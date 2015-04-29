#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class MyException : public exception
{
    private:
        const char* msg;

    public:
        MyException(char*);

        const char* what() const throw();
};

#endif // MYEXCEPTION_H
