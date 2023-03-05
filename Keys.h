/**************************************************************************************
*   Keys.h
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415   
*
*   ©2023
***************************************************************************************/

#ifndef KEYS_H
#define KEYS_H

#include <iostream>
#include <utility>
#include <tuple>
#include <math.h>
#include <string>
#include "BigInt.h";

using namespace std;

class Keys {
private:
    BigInt n, e, d;
public:

    Keys(BigInt, BigInt, BigInt);
   // Keys(string, string);

    inline pair<BigInt,BigInt> getPublic() { return make_pair(e, n); };
    inline pair<BigInt,BigInt> getPrivate() { return make_pair(d, n); };
    void saveToDisk(string dest);

};

#endif