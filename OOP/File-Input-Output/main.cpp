#include <iostream>
#include <exception>
//#include <MyException.h>
//#include <typeinfo>
#include <fstream>
#include <locale>

using namespace std;

/*istream& readData(istream &is)
{
    unsigned u;
    while(is >> u)
    {
        cout << "u = " << u << endl;
    }

    if (!is.eof())
    {
        throw MyException("Bad data!");
    }

    return is;
}*/

int main()
{
    /*try
    {
        readData(cin);
    }
    catch(MyException &m)
    {
        cerr << m.what() << endl;
        cerr << typeid(m).name() << endl;
        return 1;
    }*/

    locale::global(locale("bg_BG.UTF-8"));
    const int size = 100;
    char buff[size];

    try
    {
        ifstream file_in("./src/MyException.cpp");
        if (!file_in)
        {
            throw "Could not open file!";
        }

        cout << file_in.rdbuf() << endl;

        ofstream file_out("./stamat");
        if (!file_out)
        {
            throw "Could not create file stamat!";
        }

        // write
        file_in.seekg(0, ios::beg);
        int i = 0;
        file_out << "дфргтхъйугтфрсдгтфхъ" << endl;
        while (file_in.getline(buff, size))
        {
            file_out << ++i << ": " << buff << endl;
            cout << i << ": " << buff << endl;
        }

        file_out.close();

        ifstream in("./stamat", ios::in | ios::out);
        if (!in)
        {
            throw "Could not open file stamat!";
        }

        ostream out(in.rdbuf());
        out.seekp(16, ios::beg);
        out << "гошо";
        in.seekg(0, ios::end);
        unsigned length = in.tellg();
        cout << "length = " << length << endl;
        out.seekp((-1) * -length / 2, ios::end);
        out << "баба яга хахахахах";
    }
    catch(char* str)
    {
        cerr << str << endl;
        return 1;
    }
    catch(...)
    {
        cerr << "Unknown exception" << endl;
        return 2;
    }

    return 0;
}
