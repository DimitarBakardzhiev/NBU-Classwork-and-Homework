/* 
 * File:   FileController.cpp
 * Author: mitko
 * 
 * Created on May 7, 2015, 1:54 PM
 */

#include "FileController.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string FileController::encodeData(ifstream &file, string encFilePath, char codeChar) {
    file.seekg(0,ios::end);
    int len = file.tellg();

    ostringstream buf;
    file.seekg(0,ios::beg);
    buf << file.rdbuf();

    char fChar,sChar;

    string data = buf.str();
    char * encData = new char[2*data.length()+1];


    for (int i = 0, j=0; i <data.length(); i++,j++)
    {
            fChar = (char)((data[i]>>4) + (int)codeChar);
            sChar = (char)(((data[i]&(16-1)))+ (int)codeChar);
            encData[j++] = fChar;
            encData[j] = sChar;
    }

    encData[2*len]='\0';
    string encStr(encData);
    delete[] encData;
    ofstream encFile;
    encFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
            encFile.open(encFilePath.c_str());
            encFile << encStr;
            encFile.close();
    }
    catch(std::ifstream::failure e){
            cerr << "could not create or open file " << encFilePath.c_str() << endl;
    }
    return encStr;
}

string FileController::decodeData(string data, string decFilePath, char codeChar) {
    ostringstream buf;
    char * decData = new char[data.length()/2+1];
    for (int i = 0 , j=0; i < data.length(); i+=2){
            decData[j++] = (char)((data[i]-(int)codeChar)<<4 )|((data[i+1]-(int)codeChar));
    }

    decData[data.length()/2]='\0';
    string decStr(decData);
    delete[] decData;
    ofstream decFile;
    decFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
            decFile.open(decFilePath.c_str());
            decFile << decStr;
            decFile.close();
    }
    catch(std::ifstream::failure e){
            cerr << "could not create or open file " << decFilePath << endl;
    }
    return decStr;
}
