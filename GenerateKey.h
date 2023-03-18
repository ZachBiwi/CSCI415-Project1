/**************************************************************************************
*   GenerateKey.h
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415
*
*   ©2023
***************************************************************************************/

#include <random>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include "InfInt.h"
#include "Keys.h"

#ifndef GENERATEKEY_H
#define GENERATEKEY_H

using namespace std;

class GenerateKey {
private:
    /* data */
    vector<InfInt> first_primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,            //first 69 (haha funny number)(nice!) primes
                            31, 37, 41, 43, 47, 53, 59, 61, 67,
                            71, 73, 79, 83, 89, 97, 101, 103,
                            107, 109, 113, 127, 131, 137, 139,
                            149, 151, 157, 163, 167, 173, 179,
                            181, 191, 193, 197, 199, 211, 223,
                            227, 229, 233, 239, 241, 251, 257,
                            263, 269, 271, 277, 281, 283, 293,
                            307, 311, 313, 317, 331, 337, 347, 349
    };
    InfInt gcd(InfInt, InfInt);
    bool isPrime(InfInt, int);
    bool millerTest(InfInt, InfInt);
    InfInt powModN(InfInt, InfInt, InfInt);
    InfInt makeSuperPrime();
    InfInt modInverse(InfInt, InfInt);
    int keyLength;

public:
    GenerateKey();
    GenerateKey(int);

    Keys getNewKeypair();

};

#endif