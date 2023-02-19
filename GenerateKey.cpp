/**************************************************************************************
*   GenerateKey.cpp
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415   
*
*   ©2023
***************************************************************************************/


#include "Keys.h"
#include <string>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

const int MILLER_TEST_ITERATIONS = 7;

const short int first_primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,            //first 69 (haha funny number)(nice!) primes
                            31, 37, 41, 43, 47, 53, 59, 61, 67,
                            71, 73, 79, 83, 89, 97, 101, 103,
                            107, 109, 113, 127, 131, 137, 139,
                            149, 151, 157, 163, 167, 173, 179,
                            181, 191, 193, 197, 199, 211, 223,
                            227, 229, 233, 239, 241, 251, 257,
                            263, 269, 271, 277, 281, 283, 293,
                            307, 311, 313, 317, 331, 337, 347, 349 };


bool millerTest(unsigned short x[], int n) {
    // Corner cases make sure that n > 4
    int a = 2 + rand() % (n - 4);
 
    // Compute a^d % n
    int x = power(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
 
    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    // Return composite
    return false;

}

bool firstPrimesTest(short int n){



    return result;
}




int main() {
        int n, phi_n, e, d;
        //string p, q;
        unsigned short p[100], q[100];
        
        bool prime = false;
        while (!prime) {
            srand(time(NULL));
            for (int i = 0; i < 98; i++) {
                p[i] = rand() % 10;   //Random numbers from 0-9 placed on array
            }
            int a = 2, b = 2;
            while(a%2 == 0) {
                a = rand() % 10;
            }
            p[99] = a;

            prime = (millerTest(p, MILLER_TEST_ITERATIONS));
        }
        prime = false;
        while (!prime) {
            for (int i = 0; i < 98; i++) {
                q[i] = rand() % 10;   //Random numbers from 0-9 placed on array
            }
            while(b%2 == 0) {
                b = rand() % 10;
            }
            q[99] = b;
            prime = millerTest(q, MILLER_TEST_ITERATIONS);
         }

        
        Keys key();
        ofstream oFile;
        


    return 0;
};
