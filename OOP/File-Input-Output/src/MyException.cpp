#include "MyException.h"

#include <string>
#include <cstring>

using namespace std;

MyException::MyException(char* msg) : msg(msg)
{
}

const char* MyException::what() const throw()
{
    return this->msg;
}
