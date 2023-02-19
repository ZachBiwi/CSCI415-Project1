/**************************************************************************************
*   GenerateKey.h
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415   
*
*   ©2023
***************************************************************************************/
#ifndef GenerateKey
#define GenerateKey

#include "GenerateKey.cpp"
#include <numeric>                  //gcd( , ) included in this

using namespace std;

class GenerateKey {
private:
    int p, q, n, phi_n, e, d;


public:
    GenerateKey();                  //Default constructor
    //GenerateKey(int p);
    bool isPrime(int x);
    bool millerTest(int x, int y);
};
#endif