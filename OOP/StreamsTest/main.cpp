/* 
 * File:   main.cpp
 * Author: mitko
 *
 * Created on May 4, 2015, 11:12 PM
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int main() {

    // Задача 1
    /*
    ofstream fileBuilder("Hello.txt");
    fileBuilder << "Hello, World!\n";
    fileBuilder.close();
    
    ifstream fileReader("Hello.txt");
    string str;
    getline(fileReader, str);
    cout << str;
    fileReader.close();
    */
    
    // Задача 2
    /*
     * ofstream - за писане във файл
     * ifstream - за четене от файл
     * fstream - за четене и писане във файл
     */
    
    // Задача 3 - не минава компилация
    // Задача 4 - под ubuntu 14.04 + netbeans 8.0.2 - не хвърля грешка
    // Задача 5 - не изхвърля грешка и не се зачитат промените
    // Задача 6 - ще се използва escape на символа '\', като вместо него
    // се записва '\\'
    // Задача 7
    /*
    stringstream str;
    str << "3.14";
    double pi;
    str >> pi;
    cout << pi;
    */
    // Задача 8
    /*
     * Последователен - до определен компонент се достига след като се премине 
     * последователно през предходните
     * Пряк - до определен компонент се достига пряко чрез адрес
     */
    // Задача 9 - текстови файлове са тези, които не са отворени с ios::binary
    // Задача 10
    /*
     * get служи за извличане на информация от файл, а
     * put служи за вмъкване на данни във файл. Местят се с член-функциите
     * seekg, seekp, а позициите им се взимат с tellg, tellp
     */
    // Задача 11
    /*
     * seekg(0, ios_base::beg) - преместваме get на 0 позиции от началото
     * Поставяне по средата:
     * seekg(0, ios_base::end);
     * long len = tellg();
     * seekg(len / 2, ios_base::beg)
     */
    // Задача 12
    /*
    ifstream fileReader("Hello.txt");
    fileReader.seekg(0, ios_base::end);
    string pesho;
    fileReader >> pesho;
    if (pesho == "") {
        cout << "Empty string";
    } else {
        cout << pesho;
    }
    
    cout.seekp(0, ios_base::beg);
    cout << "baba qga";
     * последният cout не работи
     */
    
    // Задача 1
    /*
    string fileName;
    do {
        cout << "File name: ";
        cin >> fileName;
        
        ifstream fileReader(fileName.c_str());
        if (!fileReader) {
            cerr << "File " << fileName << " failed to open!" << endl;
            break;
        }

        // get symbols
        fileReader.seekg(0, ios_base::end);
        long position = fileReader.tellg();
        long size = position == 0 ? (long)0 : position - (long)1;
        cout << "Symbols: " << size << endl;
        
        // get words count
        fileReader.seekg(0, ios_base::beg);
        unsigned wordsCount = 0;
        string word = "";
        while (fileReader >> word) {
            wordsCount++;
        }
        
        cout << "Words: " << wordsCount << endl;
        
        // get lines count
        unsigned linesCount = 0;
        fileReader.seekg(0, ios_base::beg);
        string line = "";
        while (getline(fileReader, line)) {
            linesCount++;
            cout << line << endl;
        }
        
        cout << "Lines: " << linesCount << endl;
    } while (fileName != "");
    */
    
    // Задача 2
    cout << "Input keyword: ";
    string keyword;
    cin >> keyword;
    
    set<char> uniqueChars;
    for (int i = 0, length = keyword.size(); i < length; i++) {
        uniqueChars.insert(keyword[i]);
    }
    
    for (set<char>::iterator it = uniqueChars.begin(); it != uniqueChars.end(); it++) {
        cout << ' ' << *it;
    }
    
    cout << endl;
    
    return 0;
}

