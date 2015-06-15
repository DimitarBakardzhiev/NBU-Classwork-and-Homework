#include <iostream>

#include "Event.h"
#include "Conference.h"
#include "Ristream.h"
#include <fstream>
#include <typeinfo>

using namespace std;

template<typename T>
void shuffle(T &a, T &b, T &c) {
    T oldA = a;
    a = b;
    b = c;
    c = oldA;
}

int main() {

    const int size = 5;
    Event** arr = new Event*[size];
    unsigned day, month, year, invited;
    char title[21];
    char category[21];
    unsigned sectionsCount, reportsCount;
    double tax;
    
    Ristream rstream;
    for (int i = 0; i < size; i++) {
        rstream >> day >> month >> year >> title >> invited;
        
        if (i % 2 == 1) {
            rstream >> category >> sectionsCount >> reportsCount >> tax;
        }
        
        if (i % 2 == 0) {
            arr[i] = new Event(day, month, year, string(title), invited);
        } else {
            arr[i] = new Conference(day, month, year, string(title), invited,
                    category, sectionsCount, reportsCount, tax);
        }
    }
    
    ofstream eventWriter("Event.bin");
    if (!eventWriter) {
        cerr << "Failed to create events file!" << endl;
    }
    
    ofstream conferenceWriter("Conference.bin");
    if (!conferenceWriter) {
        cerr << "Failed to create conference file!" << endl;
    }

    int eventsCount = 0;
    for (int i = 0; i < size; i++) {
        if (typeid(*arr[i]) == typeid(Event)) {
            eventsCount++;
        }
    }
    
    int conferencesCount = size - eventsCount;
    eventWriter.write((char*)&eventsCount, sizeof(int));
    conferenceWriter.write((char*)&conferencesCount, sizeof(int));
    
    for (int i = 0; i < size; i++) {
        if (typeid(*arr[i]) == typeid(Event)) {
            eventWriter.write((char*)arr[i], sizeof(Event));
        } else {
            conferenceWriter.write((char*)arr[i], sizeof(Conference));
        }
    }
    
    eventWriter.close();
    conferenceWriter.close();
    
    for (int i = 0; i < size; i++) {
        delete arr[i];
    }
    
    delete[] arr;
    
    arr = new Event*[size];
    ifstream eventReader("Event.bin");
    if (!eventReader) {
        cerr << "Failed to open events file!" << endl;
    }

    int cnt;
    eventReader.read((char*)&cnt, sizeof(int));
    for (int i = 0; i < cnt; i++) {
        eventReader.read((char*)arr[i], sizeof(Event));
    }
    
    ifstream conferenceReader("Conference.bin");
    if (!conferenceReader) {
        cerr << "Failed to open conference file!" << endl;
    }

    int oldCnt = cnt;
    conferenceReader.read((char*)&cnt, sizeof(int));
    for (int i = oldCnt; i < cnt + oldCnt; i++) {
        conferenceReader.read((char*)arr[i], sizeof(Conference));
    }
    
    eventReader.close();
    conferenceReader.close();
    
    for (int i = 0; i < size; i++) {
        cout << "Object " << i + 1 << endl << endl;
        cout << *arr[i] << endl;
        delete arr[i];
    }
    
    delete[] arr;
    
    return 0;
}