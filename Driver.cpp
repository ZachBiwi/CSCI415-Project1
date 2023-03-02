/*For testing our basic RSA algoritm*/

#include <string>
#include "GenerateKeyTest.h"
#include "Keys.h"
#include "RSA.cpp"

using namespace std;

int main() {

    GenerateKeyTest keyGen;

    Keys keyPair = keyGen.getNewKeypair();
    string message1 = "I love SCSU Computer Science!";
    cout << "Message before encrytion: " << message1 << endl;

    string ciphertext = encrypt(message1, keyPair.getPublic());
    cout << "Message after encryption/before decryption: " << ciphertext << endl;

    string message2 = decrypt(ciphertext, keyPair.getPrivate());
    cout << "Message after decryption: " << message2 << endl;

}