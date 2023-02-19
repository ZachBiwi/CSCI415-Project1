/**************************************************************************************
*   Keys.h
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415   
*
*   ©2023
***************************************************************************************/

#ifndef Keys
#define Keys

#include "Keys.cpp"

using namespace std;

class Keys {
private:
    int pubKey, privKey, n;
public:

    Keys();
    Keys(string s);
    string encrypt(int n, string msg);
    string decrypt(int n);

};

#endif