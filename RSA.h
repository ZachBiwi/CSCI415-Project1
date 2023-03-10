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
#include "SuperInt.h"

using namespace std;

class RSA{
public:
    RSA(){};
    /*
    static SuperInt txtToNum(string msg){
        string translation = "";
        for (int i = 0; i < msg.length(); i++){
            int temp = (int)msg[i] - '0';
            translation = translation + to_string(temp);
        }
        return SuperInt(translation);
    }
    */
    string numToTxt(SuperInt);

    string encrypt(string, SuperInt encrypt, SuperInt modulator);

    string decrypt(string msg, SuperInt decrypt, SuperInt modulator);
};
#endif