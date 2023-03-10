#include "RSA.h"

string RSA::numToTxt(SuperInt msg) {
    string numString = msg.getDigits();
    string text = "";
    for (int i = 0; i < numString.length(); i += 2) {
        string temps = "";
        temps += numString[i];
        temps += numString[i + 1];
        int tempi = stoi(temps);
        tempi += '0';
        text += (char)tempi;
    }
    return text;
};

string RSA::encrypt(string msg, SuperInt encrypt, SuperInt modulator) {
    string translation = "";
    for (int i = 0; i < msg.length(); i++) {
        int temp = (int)msg[i] - '0';
        translation = translation + to_string(temp);
    }
    SuperInt SuperMsg = SuperInt(translation);
    SuperInt SuperCipherTxt = ((SuperMsg.pow(encrypt)) % modulator);
    return SuperCipherTxt.getDigits();
};

string RSA::decrypt(string msg, SuperInt decrypt, SuperInt modulator) {
    SuperInt SuperMsg = SuperInt(msg);
    SuperInt SuperPlainTxt = ((SuperMsg.pow(decrypt)) % modulator);
    return numToTxt(SuperPlainTxt);
};