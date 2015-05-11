/* 
 * File:   main.cpp
 * Author: mitko
 *
 * Created on May 11, 2015, 3:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int recursiveGCD(int a, int b) {
    if (b == 0 || a == b) {
        return a;
    }

    return recursiveGCD(b, a % b);
}

string recursiveReverseString(string str) {
    if (str.size() <= 1) {
        return str;
    }

    return recursiveReverseString(str.substr(1)) + str[0];
}

int main() {

    do {
        /*int a, b;
        cin >> a >> b;
        cout << "GCD: " << recursiveGCD(a, b) << endl;*/
        string str;
        cin >> str;
        cout << "Revesed: " << recursiveReverseString(str) << endl;
    } while(1);
    
    
    return 0;
}

