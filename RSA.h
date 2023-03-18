/**************************************************************************************
*   RSA.cpp
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415
*
*   ©2023
***************************************************************************************/
#ifndef RSA_H
#define RSA_H

#include <iostream>
#include <utility>
#include <tuple>
#include <math.h>
#include <string>
#include <vector>
#include <bitset>
#include "InfInt.h"

using namespace std;

class RSA {
public:
    RSA() {};

    string encrypt(string, InfInt encrypt, InfInt modulator);

    string decrypt(string msg, InfInt decrypt, InfInt modulator);

    InfInt pow(InfInt, InfInt, InfInt);

    vector<InfInt> splitPlainIntoBlocks(string);

    vector<InfInt> splitCipherIntoBlocks(string);

    string convertToAscii(string);


};
#endif