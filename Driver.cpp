/**************************************************************************************
*   Driver.cpp
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415
*
*   ©2023
***************************************************************************************/

#include <string>
#include <fstream>
#include "InfInt.h"
#include "GenerateKey.h"
#include "Keys.h"
#include "RSA.h"

using namespace std;

int main() {
    GenerateKey keyGen;
    RSA rsa;
    string message;

    ifstream inFile;
    inFile.open("Message.txt");
    
    string line;
    while (getline(inFile, line)) {
        message.append(line);
    }
    inFile.close();

    cout << "Generating Key Pair... Please Wait" << endl;
    Keys keyPair = keyGen.getNewKeypair();
    cout << "Key Pair Generated" << endl;

    string ciphertext = rsa.encrypt(message, keyPair.getEncrypt(), keyPair.getModulator());
    cout << "Message after encryption/before decryption: " << ciphertext << endl;

    string message2 = rsa.decrypt(ciphertext, keyPair.getDecrypt(), keyPair.getModulator());
    cout << "Message after decryption: " << message2 << endl;
}