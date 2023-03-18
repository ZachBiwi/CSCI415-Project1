/**************************************************************************************
*   RSA.h
*
*   Authors: Nathan O'Connor, Zachary Sawicki, Joseph Hoversten, Jacob Haapoja
*   Class: CSCI 415
*
*   ©2023
***************************************************************************************/

#include "RSA.h"

/*
* @brief RSA encryption
* @param String msg, a plaintext to be encrypted to ciphertext
* @param SuperInt encrypt, the key to be used to encrypt
* @param SuperInt modulus,
* @pre Takes a plaintext string
* @post returns ciphertext
*/
string RSA::encrypt(string msg, InfInt encrypt, InfInt modulator) {
    
    string temp;
    vector<InfInt> blocks = splitPlainIntoBlocks(msg);
    for (int i = 0; i < blocks.size(); i++) {
        InfInt temporary = pow(blocks[i], encrypt, modulator);
        temp += temporary.toString();
        if (i != blocks.size() - 1) {
            temp += ',';
        }
    }

    return temp;
};

/*
* @brief RSA Decryption
* @param String cipher, a ciphertext to be decrypted to plaintext
* @param SuperInt encrypt, the key to be used to decrypt
* @param SuperInt modulus,
* @pre takes an encrypted string
* @post returns decrypted plaintext
*/
string RSA::decrypt(string cipher, InfInt decrypt, InfInt modulator) {
    string temp;
    vector<InfInt> blocks = splitCipherIntoBlocks(cipher);
    for (int i = 0; i < blocks.size(); i++) {
        InfInt temporary = pow(blocks[i], decrypt, modulator);
        temp += temporary.toString();
    }
    return convertToAscii(temp);
};

/**
* @brief Computes power mod n on a digit
* @param base is the number being modified
* @param expo is the power to raise x to
* @param mod is the modulus applied to x^y
* @pre Takes the number for operations to be applied to, the exponent, and the modulus
* @post Returns the result of power mod n
*/
InfInt RSA::pow(InfInt base, InfInt expo, InfInt mod){

    InfInt res = 1;
    base %= mod;

    while (expo > 0){
        if (expo % 2 == 1) {
            res = ((res * base) % mod);
        }

        base = ((base * base) % mod);
        expo /= 2;

    }

    return res;
}

/**
* @brief Splits the cipher text into its comma separated blocks
* @param cipher the ciphertext which supposed to be split
* @pre Takes a ciphertext string that has been split by commas
* @post Returns a vector of InfInts used for decryption
*/
vector<InfInt> RSA::splitCipherIntoBlocks(string cipher) {
    
    vector<InfInt> blocks;
    string temp;
    for (int i = 0; i < cipher.length() + 1; i++) {
        if (cipher[i] == ',' || i == cipher.length()) {
            blocks.push_back(temp);
            temp = "";
        }
        else {
            temp.push_back(cipher[i]);
        }
    }
    return blocks;
}

/**
* @brief Splits a plaintext message into three byte blocks
* @param msg is the plaintext message to split into blocks
* @pre Takes a string message to be split into blocks
* @post Returns msg split into a vector of 3 byte blocks
*/
vector<InfInt> RSA::splitPlainIntoBlocks(string msg) {
    vector<InfInt> blocks;

    for (int i = 0; i < (msg.length()); i++){
        string temp;

        if (msg.length() - i >= 3){
            temp.append(to_string(int(msg[i])));
            temp.append(to_string(int(msg[++i])));
            temp.append(to_string(int(msg[++i])));
        }
        else if (msg.length() - i == 2){
            temp.append(to_string(int(msg[i])));
            temp.append(to_string(int(msg[++i])));
            temp.append(to_string(48));
        }
        else if (msg.length() - i == 1){
            temp.append(to_string(int(msg[i])));
            temp.append(to_string(48));
            temp.append(to_string(48));
        }
        blocks.push_back(temp);
    }
    return blocks;
}

/**
* @brief Converts ascii values into character values
* @param message is a string of decimals to be converted to ascii
* @post returns the string in ascii
*/
string RSA::convertToAscii(string message) {
    int digit = 0;
    string output;
    for (int i = 0; i < message.length(); i++) {
        digit = digit * 10 + (message[i] - '0');
        if (digit >= 32 && digit <= 122) {
            output.push_back((char)digit);
            digit = 0;
        }
    }

    //Remove 0 padding
    for (int i = output.length() - 1; i >= 0; i--) {
        if (output[i] == '0') {
            output.pop_back();
        }
        else {
            break;
        }
    }
    return output;
}