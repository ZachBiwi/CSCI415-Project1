/*For testing our basic RSA algoritm*/

#include <string>
#include "SuperInt.h"
#include "GenerateKeyTest.h"
#include "Keys.h"
#include "RSA.h"
#include "SuperInt.h"

using namespace std;

int main() {
    GenerateKeyTest keyGen;
    RSA rsa;

    cout << "Generating Key Pair... Please Wait" << endl;
    Keys keyPair = keyGen.getNewKeypair();
    cout << "Key Pair Generated" << endl;

    string message1 = "I love SCSU Computer Science!";
    cout << "Message before encrytion: " << message1 << endl;

    string ciphertext = rsa.encrypt(message1, keyPair.getEncrypt(), keyPair.getModulator());
    cout << "Message after encryption/before decryption: " << ciphertext << endl;

    string message2 = rsa.decrypt(ciphertext, keyPair.getDecrypt(), keyPair.getModulator());
    cout << "Message after decryption: " << message2 << endl;

}