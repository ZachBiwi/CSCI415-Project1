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
#include <math.h>
#include <string>
#include "SuperInt.h"

using namespace std;

class Keys {
private:
    SuperInt n, e, d;
public:

    Keys(SuperInt, SuperInt, SuperInt);
   // Keys(string, string);

    inline SuperInt getEncrypt()    {return e;};
    inline SuperInt getDecrypt()    {return d;};
    inline SuperInt getModulator()  {return n;};
    void saveToDisk(string dest);
};

#endif