#include "GenerateKeyTest.h"

using namespace std;

GenerateKeyTest::GenerateKeyTest() {

}

int GenerateKeyTest::gcd(int x, int y) {
    int temp;
    while (1) {
        temp = x % y;
        if (temp == 0)
            return y;
        x = y;
        y = temp;
    }
}

int GenerateKeyTest::lcm(int x, int y){
    return ((abs(x * y) / gcd(x,y)));
}

int GenerateKeyTest::calculateD(int e, int lambdaN) {
    for (int i = 1; i < lambdaN - 1; i++){
        if( (i*e) % lambdaN == 1){
            return i;
        }
    }
}

Keys GenerateKeyTest::getNewKeypair() {
    vector<int> first_primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,            //first 69 (haha funny number)(nice!) primes
                            31, 37, 41, 43, 47, 53, 59, 61, 67,
                            71, 73, 79, 83, 89, 97, 101, 103,
                            107, 109, 113, 127, 131, 137, 139,
                            149, 151, 157, 163, 167, 173, 179,
                            181, 191, 193, 197, 199, 211, 223,
                            227, 229, 233, 239, 241, 251, 257,
                            263, 269, 271, 277, 281, 283, 293,
                            307, 311, 313, 317, 331, 337, 347, 349 
                            };
    srand(time(0));
    int p, q, n, e, d, lambdaN;
    p = first_primes[rand() % 69];
    q = first_primes[rand() % 69];
    n = p * q;
    lambdaN = lcm(p - 1, q - 1);
    e = 65537;
    d = calculateD(e, lambdaN);
    return Keys(n, e, d);
}