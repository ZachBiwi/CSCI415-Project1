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
#include <chrono>
#include <time.h>
#include "InfInt.h"
#include "GenerateKey.h"
#include "Keys.h"
#include "RSA.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream inFile;
    ofstream outFile;
    RSA rsa;
    double encryptTotal = 0, decryptTotal = 0;

    if (argc < 3) {
        cout << "Invalid argument: ./rsa KeyLength Runs" << endl;
        return -1;
    }

    GenerateKey keyGen(atoi(argv[1]));
    int runs = atoi(argv[2]);

    for (int i = 0; i < runs; i++) {
        string message, line, cipherText;
        cout << "Run " << (i + 1) << ":\n";

        inFile.open("Message.txt");
        while (getline(inFile, line)) {
            message.append(line);
        }
        inFile.close();

        cout << "Generating Key Pair... Please Wait" << endl;

        Keys keyPair = keyGen.getNewKeypair();
        cout << "Key Pair Generated" << endl;

        auto startEnc = std::chrono::steady_clock::now();
        cipherText = rsa.encrypt(message, keyPair.getEncrypt(), keyPair.getModulator());
        auto endEnc = std::chrono::steady_clock::now();

        outFile.open("Cipher.txt");
        outFile << cipherText;
        outFile.close();

        cipherText = "";
        inFile.open("Cipher.txt");
        while (getline(inFile, line)) {
            cipherText.append(line);
        }
        inFile.close();

        cout << "Message after encryption/before decryption: " << cipherText << endl;

        auto startDec = std::chrono::steady_clock::now();
        string message2 = rsa.decrypt(cipherText, keyPair.getDecrypt(), keyPair.getModulator());
        auto endDec = std::chrono::steady_clock::now();
        cout << "Message after decryption: " << message2 << endl;

        cout << "Run " << (i + 1) << " Encrypt Time: " <<  chrono::duration_cast<chrono::milliseconds>(endEnc - startEnc).count() << " ms\n";
        cout << "Run " << (i + 1) << " Decrypt Time: " << chrono::duration_cast<chrono::milliseconds>(endDec - startDec).count() << " ms\n\n";

        encryptTotal += chrono::duration_cast<chrono::milliseconds>(endEnc - startEnc).count();
        decryptTotal += chrono::duration_cast<chrono::milliseconds>(endDec - startDec).count();
    }

    cout << "Average Encrypt Time: " << (encryptTotal / runs) << " ms\n";
    cout << "Average Decrypt Time: " << (decryptTotal / runs) << " ms\n";

}