/* 
 * File:   main.cpp
 * Author: mitko
 *
 * Created on May 14, 2015, 1:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Product.h"
#include "Delivery.h"
#include "Ristream.h"

using namespace std;

int main() {

    /*Product products[5];
    Ristream ri;
    unsigned id, w, h, l;
    double kg;
    char name[21];
    
    for (int i = 0; i < sizeof(products) / sizeof(products[0]); i++) {
        ri >> id >> w >> h >> l >> kg >> name;
        products[i] = Product(name, id, kg, h, w, l);
    }
    */
    
    /*
    ofstream fileWriter("products.txt");
    if (!fileWriter) {
        cerr << "File creation failed!" << endl;
        return 1;
    }

    fileWriter << sizeof(products) / sizeof(products[0]);
    for (int i = 0; i < sizeof(products) / sizeof(products[0]); i++) {
        fileWriter << products[i] << endl;
    }
    
    fileWriter.close();
    
    ifstream fileReader("products.txt");
    if (!fileReader) {
        cerr << "Failed to open file!" << endl;
        return 2;
    }

    char line[200];
    int count = 0;
    while (fileReader.getline(line, 199)) {
        if (count % 6 == 0) {
            cout << endl;
            cout << "Product number: " << count / 6 + 1 << endl;
        }

        cout << line << endl;
        count++;
    }
     */
    
    /*ofstream fileWriter("products.bin", ios::binary);
    if (!fileWriter) {
        cerr << "Failed to create binary file!" << endl;
        return 1;
    }

    int count = sizeof(products) / sizeof(products[0]);
    fileWriter.write((char*)&count, sizeof(count));
    for (int i = 0; i < count; ++i) {
        fileWriter.write((char*)&products[i], sizeof(Product));
    }
    
    fileWriter.close();
    
    ifstream fileReader("products.bin", ios::binary);
    if (!fileReader) {
        cerr << "Failed to open binary file!" << endl;
        return 2;
    }

    fileReader.read((char*)&count, sizeof(int));
    cout << "Number of products: " << count << endl;
    for (int i = 0; i < sizeof(products) / sizeof(products[0]); ++i) {
        fileReader.read((char*)&products[i], sizeof(Product));
        cout << endl << "Product number: " << i + 1;
        cout << products[i] << endl;
    }
    
    fileReader.close();
    */
    
    const int size = 5;
    Delivery **arr = new Delivery*[size];
    Ristream rstream;
    unsigned id, w, h, l;
    double kg;
    char name[21];
    char deliveryName[31];
    double price;
    unsigned count;
    
    for (int i = 0; i < size; i++) {
        rstream >> id >> w >> h >> l >> kg;
        rstream >> name >> deliveryName >> price >> count;
        
        arr[i] = new Delivery(name, id, kg, h, w, l,
                deliveryName, price, count);
    }
    
    ofstream binaryFileWriter("Deliveries.bin", ios::binary);
    if (!binaryFileWriter) {
        cerr << "Failed to create binary file!" << endl;
        return 1;
    }
    
    binaryFileWriter.write((char*)&size, sizeof(int));
    for (int i = 0; i < size; i++) {
        binaryFileWriter.write((char*)arr[i], sizeof(Delivery));
    }
    
    binaryFileWriter.close();
    
    ifstream binaryFileReader("Deliveries.bin", ios::binary);
    if (!binaryFileReader) {
        cerr << "Failed to open binary file!" << endl;
    }

    int len;
    binaryFileReader.read((char*)&len, sizeof(int));
    for (int i = 0; i < len; i++) {
        binaryFileReader.read((char*)arr[i], sizeof(Delivery));
        cout << endl << endl << "Delivery number: " << i + 1 << endl;
        cout << *arr[i] << endl;
    }
    
    binaryFileReader.close();
    
    return 0;
}