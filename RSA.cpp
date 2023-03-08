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
#include "BigInt.h";

using namespace std;

/*
static BigInt txtToNum(string msg){
    string translation = "";
    for (int i = 0; i < msg.length(); i++){
        int temp = (int)msg[i] - '0';
        translation = translation + to_string(temp);
    }
    return BigInt(translation);
}
*/

static string numToTxt(BigInt msg){
    string numString = msg.getDigits();
    string text = "";
    for (int i = 0; i < numString.length(); i += 2){
        string temps = "";
        temps += numString[i];
        temps += numString[i+1];
        int tempi = stoi(temps);
        tempi += '0';
        text += (char)tempi;
    }
    return text;
}

static string encrypt(string msg, pair<BigInt,BigInt> pubKey) {
    string translation = "";
    for (int i = 0; i < msg.length(); i++){
        int temp = (int)msg[i] - '0';
        translation = translation + to_string(temp);
    }
    BigInt bigMsg = BigInt(translation);
    BigInt bigCipherTxt = ((bigMsg ^ pubKey.second) % pubKey.first);
    return bigCipherTxt.getDigits();
}

static string decrypt(string msg, pair<BigInt,BigInt> privKey) {
    BigInt bigMsg = BigInt(msg);
    BigInt bigPlainTxt = ((bigMsg ^ privKey.first) % privKey.second);
    return numToTxt(bigPlainTxt);
}

#endif