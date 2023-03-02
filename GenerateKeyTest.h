#include <random>
#include <ctime>
#include <vector>
#include "Keys.h"

#ifndef GENERATEKEYTEST_H
#define GENERATEKEYTEST_H

using namespace std;

class GenerateKeyTest{
private:
    /* data */
    vector<int> first_primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,            //first 69 (haha funny number)(nice!) primes
                            31, 37, 41, 43, 47, 53, 59, 61, 67,
                            71, 73, 79, 83, 89, 97, 101, 103,
                            107, 109, 113, 127, 131, 137, 139,
                            149, 151, 157, 163, 167, 173, 179,
                            181, 191, 193, 197, 199, 211, 223,
                            227, 229, 233, 239, 241, 251, 257,
                            263, 269, 271, 277, 281, 283, 293,
                            307, 311, 313, 317, 331, 337, 347, 349 
                            };

    int choose();
    void findPhi();
    void findLambda();
    int gcd(int, int);
    int lcm(int, int);
    int calculateD(int, int);
    int publicKey(int, int);
    int privateKey(int, int);

public:
    GenerateKeyTest();
    
    Keys getNewKeypair();

};

#endif