/**************************************************************************************
*   Encrypt.cpp
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415   
*
*   ©2023
***************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "GenerateKey.h"
#include "Keys.h"

using namespace std;

const string help = "Usage: ./RSA targetFile [keypair] [-e]\n";

int main(int argc, char *argv[]) {
    if (argc > 4 || argc < 3) {         //Number of args must be 3-4
        cout << "Invalid number of arguments!\n";
        cout << help;
        return 1;        
    }
    Keys keypair;
    else if (argc == 3){            //Generate a key pair for the user
        GenerateKey generator();
    } else /* argc == 4 */ {        //User defines a key pair
        
    }
    
    string input;
    ifstream outfile, keyPair;
    ofstream infile;

    return 0;
}