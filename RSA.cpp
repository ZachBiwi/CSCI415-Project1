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
* @brief simple function to convert a SuperInt into a string
* @param SuperInt msg to be converted to string
* @pre Takes a SuperInt
* @post Returns string
*/
string RSA::numToTxt(InfInt msg) {
    string numString = msg.toString();
    string text = "";
    for (int i = 0; i < numString.length(); i += 2) {
        string temps = "";
        temps += numString[i];
        temps += numString[i + 1];
        int tempi = stoi(temps);
        tempi += ' ';
        text += (char)tempi;
    }
    return text;
};

/*
* @brief RSA encryption
* @param String msg, a plaintext to be encrypted to ciphertext
* @param SuperInt encrypt, the key to be used to encrypt
* @param SuperInt modulus,
* @pre Takes a plaintext string
* @post returns ciphertext
*/
string RSA::encrypt(string msg, InfInt encrypt, InfInt modulator) {
    string translation = "";
    for (int i = 0; i < msg.length(); i++) {
        int temp = (int)msg[i] - ' ';
        if(temp < 10)
            translation.push_back('0');
        translation = translation + to_string(temp);
    }

    InfInt SuperMsg = InfInt(translation);
    InfInt SuperCipherTxt = pow(SuperMsg, encrypt, modulator);
    return SuperCipherTxt.toString();
};

/*
* @brief RSA Decryption
* @param String msg, a ciphertext to be decrypted to plaintext
* @param SuperInt encrypt, the key to be used to decrypt
* @param SuperInt modulus,
* @pre takes an encrypted string
* @post returns decrypted plaintext
*/
string RSA::decrypt(string msg, InfInt decrypt, InfInt modulator) {
    InfInt SuperMsg = InfInt(msg);
    InfInt SuperPlainTxt = pow(SuperMsg, decrypt, modulator);
    return numToTxt(SuperPlainTxt);
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

