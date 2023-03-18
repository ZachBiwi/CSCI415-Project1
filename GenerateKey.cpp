/**************************************************************************************
*   GenerateKey.cpp
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415
*
*   ©2023
***************************************************************************************/

#include "GenerateKey.h"

using namespace std;

GenerateKey::GenerateKey() {
    keyLength = 100;
}

GenerateKey::GenerateKey(int length) {
    keyLength = length;
}

/**
* @brief Mod inverse method for a number
* @param a the number to perform the calculation on
* @param mod the modulo to use for calculation
* @pre Accepts a number to to compute the mod inverse on and the modulo
* @post Returns the modular inverse of a
*/
InfInt GenerateKey::modInverse(InfInt a, InfInt mod){
    InfInt infMod = mod;
    InfInt y = 0, x = 1;

    if (mod == 1) {
        return 0;
    }
    while (a > 1) {
        InfInt q = a / mod;
        InfInt t = mod;
        mod = a % mod;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += infMod;
    }
    return x;
}

/**
* @brief Tests if a number is prime
* @param prime the value to test primality of
* @param runs the number of times to test primality of prime
* @pre Accepts a prime to test and the number of times to test it
* @post Returns true or false depending of if prime is likely prime
*/
bool GenerateKey::isPrime(InfInt prime, int runs){
    if (prime <= 1 || prime == 4) {
        return false;
    }
    if (prime <= 3) {
        return true;
    }

    InfInt d = prime - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    for (int i = 0; i < runs; i++) {
        if (!millerTest(d, prime)) {
            return false;
        }
    }

    return true;
}

/**
* @brief Computes the miller test on a possible prime value
* @param d is a prime relative to n
* @param n is the potential prime to test for primality
* @pre Accepts an oddprime relative to the prime being tested and it acceptts the prime to test
* @post Returns true or false depending on if n is likely prime
*/
bool GenerateKey::millerTest(InfInt d, InfInt n){

    InfInt ran = 2 + rand();
    InfInt a = ran % (n - 4);
    InfInt x = powModN(a, d, n);

    if (x == 1 || x == n - 1) {
        return true;
    }

    while (d != n - 1){
        x = (x * x) % n;
        d *= 2;
        if (x == 1)      return false;
        if (x == n - 1)    return true;
    }

    return false;
}

/**
* @brief Computes power mod n on a digit
* @param base is the number being modified
* @param expo is the power to raise x to
* @param mod is the modulus applied to x^y
* @pre Takes the number for operations to be applied to, the exponent, and the modulus
* @post Returns the result of power mod n
*/
InfInt GenerateKey::powModN(InfInt base, InfInt expo, InfInt mod) {
    InfInt res = 1;
    base %= mod;

    while (expo > 0) {
        if (expo % 2 == 1) {
            res = ((res * base) % mod);
        }

        base = ((base * base) % mod);
        expo /= 2;

    }

    return res;
}

/**
* @brief Determines gcd of two values
* @param x first value to find the gcd for
* @param y first value to find the gcd for
* @pre Accepts two values to find the gcd for
* @post Returns the gcd of x and y
*/
InfInt GenerateKey::gcd(InfInt x, InfInt y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

/**
* @brief Generates a large prime with size 100
* @post Returns a large prime with size 100
*/
InfInt GenerateKey::makeSuperPrime() {
    string bInt;
    bool primeFlag = false;
    srand(time(0));         //seed
    while (!primeFlag) { // primefalg
        bInt = "";
        for (int i = 0; i < keyLength; i++) {
            bInt = bInt + to_string(rand() % 10);
        }
        primeFlag = isPrime(InfInt(bInt), 5);
    }
    return InfInt(bInt);
}

/**
* @brief Gets a new key pair. Determines n and lambdaN.
* @post Returns a an instance of the Keys class
*/
Keys GenerateKey::getNewKeypair() {

    InfInt p,q, n, e, d, lambdaN;
    bool done = false;

    p = makeSuperPrime();
    while(!done){
        q = makeSuperPrime();
        lambdaN = (p - 1) * (q - 1);
        e = 65537;

        if (p != q && gcd(e, lambdaN) == 1) {
            done = true;
        }
        
    }
    n = p * q;  
    d = modInverse(e, lambdaN);
    return Keys(n, e, d);
}