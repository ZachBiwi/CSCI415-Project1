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
#include "InfInt.h"

using namespace std;

class Keys {
private:
    InfInt n, e, d;
public:

    Keys(InfInt, InfInt, InfInt);

    inline InfInt getEncrypt() { return e; };
    inline InfInt getDecrypt() { return d; };
    inline InfInt getModulator() { return n; };
    void saveToDisk(string dest);
};

#endif