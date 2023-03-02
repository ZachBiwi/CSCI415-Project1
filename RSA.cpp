/**************************************************************************************
*   RSA.cpp
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415   
*
*   ©2023
***************************************************************************************/
#ifndef RSA
#define RSA

#include <iostream>
#include <utility>
#include <tuple>
#include <math.h>
#include <string>

using namespace std;

static string encrypt(string msg, pair<int,int> pubKey) {
    return to_string((((int) pow(stoi(msg), pubKey.second)) % pubKey.first));
}

static string decrypt(string msg, pair<int,int> privKey) {
    return to_string((((int) pow(stoi(msg), privKey.first)) % privKey.second));
}

#endif