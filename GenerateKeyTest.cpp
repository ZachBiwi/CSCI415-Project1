#include "GenerateKeyTest.h"

using namespace std;

GenerateKeyTest::GenerateKeyTest() {

}

SuperInt GenerateKeyTest::powModN(SuperInt x, SuperInt y, SuperInt p) {
    SuperInt res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > SuperInt('0'))
    {
        // If y is odd, multiply x with result
        if (y % SuperInt('2') == SuperInt('0'))
            res = (res * x) % p;

        // y must be even now
        y = y / SuperInt('2'); // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// This function is called for all k trials. It returns
// false if n is composite and returns true if n is
// probably prime.
// d is an odd number such that  d*2 = n-1
// for some r >= 1
bool GenerateKeyTest::millerTest(SuperInt d, SuperInt n) // miillerTest
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    SuperInt a = 2 + rand() % (n - 4);

    // Compute a^d % n
    SuperInt x = powModN(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n - 1)    return true;
    }

    // Return composite
    return false;
}

bool GenerateKeyTest::isPrime(SuperInt prime, int runs)
{
    // Corner cases
    if (prime <= SuperInt(1) || prime == SuperInt(4)) {
        return false;
    }
    if (prime <= SuperInt(3)) {
        return true;
    }

    // Find r such that n = 2^d * r + 1 for some r >= 1
    SuperInt oddPrime = prime - 1;
    SuperInt two = 2;
    SuperInt zero = '0';
    while (oddPrime % two == zero)
        oddPrime /= 2;

    // Iterate given number of 'k' times
    for (int i = 0; i < runs; i++)
        if (!millerTest(oddPrime, prime))
            return false;

    return true;
}

SuperInt GenerateKeyTest::gcd(SuperInt x, SuperInt y) {
    SuperInt temp;
    while (1) {
        temp = x % y;
        if (temp == SuperInt('0'))
            return y;
        x = y;
        y = temp;
    }
}

SuperInt GenerateKeyTest::lcm(SuperInt x, SuperInt y) {
    return ((x * y) / gcd(x, y));
}

SuperInt GenerateKeyTest::calculateD(SuperInt e, SuperInt lambdaN) {
    for (SuperInt i = 1; i < lambdaN - 1; i++) {
        if ((i * e) % lambdaN == 1) {
            return i;
        }
    }
}

SuperInt GenerateKeyTest::makeSuperPrime() {
    string bInt;
    bool primeFlag = false;
    while (!primeFlag) { // primefalg
        bInt = "";
        for (int i = 0; i < 100; i++) {
            bInt = bInt + to_string(rand() % 10);
        }
        primeFlag = isPrime(SuperInt(bInt), 5);
    }
    return SuperInt(bInt);
}

Keys GenerateKeyTest::getNewKeypair() {

    SuperInt p, q, n, e, d, lambdaN;

    p = makeSuperPrime();
    q = makeSuperPrime();

    //p = first_primes[rand() % 69];
    //q = first_primes[rand() % 69];
    n = p * q;
    lambdaN = lcm(p - 1, q - 1);
    e = 65537;
    d = calculateD(e, lambdaN);
    return Keys(n, e, d);
}