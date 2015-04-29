#include <iostream>
#include <Building.h>
#include <Office.h>
#include <stdlib.h>

using namespace std;

int main()
{
//    {
//        Building nbu("NBU", "Montevideo 21 Str.", 6000, 28, 8);
//        cout << nbu << endl;
//        nbu.usability(cout);
//    }
//    {
//        Office nbu("NBU", "Montevideo 21 Str.", 6000, 28, 8, 85);
//        cout << nbu;
//        nbu.usability(cout);
//    }
//    {
//        Office nbuBuilding("NBU", "Montevideo 21 Str.", 6000, 28, 8, 95);
//        Building &nbu = nbuBuilding;
//        cout << nbu;
//        nbu.usability(cout);
//    }
    {
        cout << "Print array of buildings: " << endl;
        Building **buildingArray = new Building*[4];
        for (int i = 0; i < 4; i++)
        {
            buildingArray[i] = (rand() % 2 == 0) ?
                new Building("NBU", "Montevideo 21 Str.", (rand() % 6001 + 1), rand() % 51 + 1, rand() % 6 + 7) :
                    new Office("NBU", "Montevideo 21 Str.", (rand() % 6001 + 1), (rand() % 51 + 1), 8, 95);
            cout << *buildingArray[i];
            buildingArray[i]->usability(cout);
        }

        for (int i = 0; i < 4; i++)
        {
            delete buildingArray[i];
        }

        delete[] buildingArray;
    }

    return 0;
}
