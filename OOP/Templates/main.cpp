/* 
 * File:   main.cpp
 * Author: mitko
 *
 * Created on May 7, 2015, 1:18 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Container.h"
#include "Ristream.h"
#include "FileController.h"

using namespace std;

int main() {

    int n = 5;
    Container<int, double> *contArr = new Container<int, double>[n];
    Ristream ris;
    int a;
    double b;
    
    for (int i = 0; i < n; i++) {
        ris >> a >> b;
        contArr[i] = Container<int, double>(a, b);
    }
    
    ofstream file("container.txt");
    if (!file) {
        cerr << "File could not be created!\n";
    }

    for (int i = 0; i < n; i++) {
        file << contArr[i] << endl;
    }
    
    file.close();
    ifstream fileRead("container.txt");
    if (!file) {
        cerr << "File could not be opened!\n";
    }
    
    FileController fCode;
    string encodedData = fCode.encodeData(fileRead, "encodedContainer.txt", '%');
    string decodedData = fCode.decodeData(encodedData, "encodedContainer.txt", '%');
            
    delete[] contArr;
    
    return 0;
}

