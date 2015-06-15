#include <cstdlib>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include "Appointment.h"

using namespace std;

int main() {

    // Въпрос 1 - n позиции - итераторът превърта, ако е нужно
    
    // Въпрос 2 - при месте на итератора след края той се мести в началото на
    // структурата от данни, при местене от началото назад ще отиде в края. При работа с
    // елементи преди началото и след края се работи реално с елементите от контейнера
    // сочени от итератора след превъртането (g++ компилатор).
    
    // Въпрос 3
//    list<string> names;
//    list<string>::iterator p = names.begin();    - p е на позиция 0
//    names.insert(p, "Tom");    - p е на позиция 1 след insert
//    p = names.begin();    - p е отново на позиция 0
//    names.insert(p, "Dick");    - Dick ще бъде вмъкнат преди Tom
//    p++;    - p е на позиция 1 и се мести на позиция 2 (след Tom)
//    names.insert(p, "Harry");    - Harry е вмъкнат на последна позиция
//    for (p = names.begin(); p != names.end(); p++)
//        cout << *p << "\n";    - Dick --> Tom --> Harry
    
    /*list<int> a;
    for (int i = 0; i < 5; i++) {
        a.push_back(i + 1);
    }
    
    list<int>::iterator it = a.begin();
    it--;
    a.insert(it, 10);
    
    for (list<int>::iterator it = a.begin(); it != a.end(); it++) {
        cout << *it << endl;
    }*/
    
    vector<Appointment> container;
    container.push_back(Appointment(DateTime(2015, 6, 2, 12, 0)));
    container.push_back(Appointment(DateTime(2015, 5, 31, 14, 0)));
    container.push_back(Appointment(DateTime(2015, 6, 1, 10, 0)));
    
    // insertion sort
    for (int i = 1; i < container.size(); i++) {
        int j = i;
        while (j > 0 && container[j] < container[j - 1]) {
            swap(container[j], container[j - 1]);
            j--;
        }
    }
    
    ofstream fileWriter("appointments.txt");
    if (!fileWriter) {
        cerr << "Failed to create file!" << endl;
    }

    for (int i = 0, len = container.size(); i < len; i++) {
        fileWriter << container[i] << endl << endl;
    }
    
    fileWriter.close();
    
    return 0;
}

