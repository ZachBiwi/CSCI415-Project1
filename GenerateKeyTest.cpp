#include "GenerateKeyTest.h"

using namespace std;

GenerateKeyTest::GenerateKeyTest() {

}

BigInt GenerateKeyTest::powModN(BigInt x, BigInt y, BigInt p){
    BigInt res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > BigInt('0'))
    {
        // If y is odd, multiply x with result
        if (y % BigInt('2') == BigInt('0'))
            res = (res*x) % p;
 
        // y must be even now
        y = y/BigInt('2'); // y = y/2
        x = (x*x) % p;
    }
    return res;
}
 
// This function is called for all k trials. It returns
// false if n is composite and returns true if n is
// probably prime.
// d is an odd number such that  d*2 = n-1
// for some r >= 1
bool GenerateKeyTest::millerTest(BigInt d, BigInt n) // miillerTest
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    BigInt a = 2 + rand() % (n - 4);
 
    // Compute a^d % n
    BigInt x = powModN(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
 
    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    // Return composite
    return false;
}

bool GenerateKeyTest::isPrime(BigInt prime, int runs)
{
    // Corner cases
    if (prime <= 1 || prime == 4)  return false;
    if (prime <= 3) return true;
 
    // Find r such that n = 2^d * r + 1 for some r >= 1
    BigInt oddPrime = prime - 1;
    BigInt two = 2;
    BigInt zero = '0';
    while (oddPrime % two == zero)
        oddPrime /= 2;
 
    // Iterate given number of 'k' times
    for (int i = 0; i < runs; i++)
         if (!millerTest(oddPrime, prime))
              return false;
 
    return true;
}

BigInt GenerateKeyTest::gcd(BigInt x, BigInt y) {
    BigInt temp;
    while (1) {
        temp = x % y;
        if (temp == BigInt('0'))
            return y;
        x = y;
        y = temp;
    }
}

BigInt GenerateKeyTest::lcm(BigInt x, BigInt y){
    return ((x * y) / gcd(x,y));
}

BigInt GenerateKeyTest::calculateD(BigInt e, BigInt lambdaN) {
    for (BigInt i = 1; i < lambdaN - 1; i++){
        if( (i*e) % lambdaN == 1){
            return i;
        }
    }
}

BigInt GenerateKeyTest::makeBigPrime(){
    string bInt;
    bool primeFlag = false;
    while(!primeFlag) { // primefalg
        bInt = "";
        for(int i = 0; i < 100; i++){
            bInt = bInt + to_string(rand() % 10);
        }
        primeFlag = isPrime(BigInt(bInt), 5);
    }
    return BigInt(bInt);
}

Keys GenerateKeyTest::getNewKeypair() { 
    
    BigInt p, q, n, e, d, lambdaN;

    p = makeBigPrime();
    q = makeBigPrime();

    //p = first_primes[rand() % 69];
    //q = first_primes[rand() % 69];
    n = p * q;
    lambdaN = lcm(p - 1, q - 1);
    e = 65537;
    d = calculateD(e, lambdaN);
    return Keys(n, e, d);
}