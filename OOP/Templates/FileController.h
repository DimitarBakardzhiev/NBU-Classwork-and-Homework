/* 
 * File:   FileController.h
 * Author: mitko
 *
 * Created on May 7, 2015, 1:54 PM
 */

#ifndef FILECONTROLLER_H
#define	FILECONTROLLER_H

#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class FileController{
public:
	static string encodeData(ifstream &file, string encFilePath, char);
	static string decodeData(string data, string decFilePath, char);
};

#endif	/* FILECONTROLLER_H */

