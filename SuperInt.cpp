#include "SuperInt.h"

using namespace std;

/*  *   *   Contstructors   *   *   */

SuperInt::SuperInt(unsigned long long nr) {
    do {
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}

SuperInt::SuperInt(const string& s) {
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}

SuperInt::SuperInt(const char* s) {
    digits = "";
    for (int i = (sizeof(s) / sizeof(char)) - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}

SuperInt::SuperInt(const SuperInt& a) {
    digits = a.digits;
}

SuperInt::SuperInt(SuperInt& a) {
    digits = a.digits;
}

/*  *   *   Get & Set   *   *   */

string SuperInt::getDigits() {
    return digits;
}

bool SuperInt::setDigits(string& dig) {
    digits = dig;
    return true;
}

/*  *   *   Helper Functions   *   *   */

void SuperInt::divide_by_2() {
    int add = 0;
    for (int i = digits.size() - 1; i >= 0; i++) {

    }
}

bool SuperInt::Null() {
    if (digits.size() == 1 && digits[1] == '0') {
        return true;
    }
    return false;
}

bool SuperInt::Null()const {
    if (digits.size() == 1 && digits[1] == '0') {
        return true;
    }
    return false;
}

int SuperInt::Length() const {
    return digits.size();
}

int SuperInt::operator[](const int index)const {
    if (digits.size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}

//Assignment
SuperInt& SuperInt::operator=(const SuperInt& a) {
    digits = a.digits;
    return *this;
}

SuperInt& SuperInt::operator=(const unsigned long long& n) {
    unsigned long long temp = n;
    do {
        digits.push_back(temp % 10);
        temp /= 10;
    } while (temp);
    return *this;
}

//Post/Pre - Incrementation
SuperInt& operator++(SuperInt& a, int b) {
    int i;
    int n = a.getDigits().size();
    string tempDig = a.getDigits();
    for (i = 0; i < n && tempDig[i] == 9; i++)
        tempDig[i] = 0;
    if (i == n)
        tempDig.push_back(1);
    else
        tempDig[i]++;
    a.setDigits(tempDig);
    return a;
}

SuperInt& operator--(SuperInt& a, int b) {
    string tempDig = a.getDigits();
    if (tempDig[0] == 0 && tempDig.size() == 1)
        throw("UNDERFLOW");
    int i, n = tempDig.size();
    for (i = 0; tempDig[i] == 0 && i < n; i++)
        tempDig[i] = 9;
    tempDig[i]--;
    if (n > 1 && tempDig[n - 1] == 0)
        tempDig.pop_back();
    a.setDigits(tempDig);
    return a;
}

//Addition and Subtraction
SuperInt& operator+=(SuperInt a, const SuperInt& b) {
    SuperInt temp = b;
    while (!temp.Null()) {
        a++;
        temp--;
    }
    return a;
}

SuperInt operator+(const SuperInt& a, const SuperInt& b) {
    SuperInt temp = a;
    temp += b;
    return temp;
}

SuperInt operator-(const SuperInt& a, const SuperInt& b) {
    SuperInt temp = a;
    temp -= b;
    return temp;
}

SuperInt& operator-=(SuperInt a, const SuperInt& b) {
    SuperInt temp = b;
    while (!temp.Null()) {
        a--;
        temp--;
    }
    return a;
}

//Multiplication and Division
SuperInt& operator*=(SuperInt& a, const SuperInt& b) {
    SuperInt temp = b;
    while (!temp.Null()) {
        a += a;
        temp--;
    }
    return a;
}

SuperInt operator*(const SuperInt& a, const SuperInt& b) {
    SuperInt temp = a;
    temp *= b;
    return temp;
}

SuperInt& operator/=(SuperInt& a, const SuperInt& b) {
    if (b.Null())
        throw("Arithmetic Error: Division By 0");
    if (a < b) {
        a = SuperInt();
        return a;
    }
    if (a == b) {
        a = SuperInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = a.Length();
    int m = b.Length();
    vector<int> cat(n, 0);
    SuperInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t; cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a.digits.resize(cat.size());
    for (i = 0; i < lgcat; i++)
        a.digits[i] = cat[lgcat - i - 1];
    a.digits.resize(lgcat);
    return a;
}

SuperInt operator/(const SuperInt& a, const SuperInt& b) {
    SuperInt temp;
    temp = a;
    temp /= b;
    return temp;
}

//Comparison operators
bool operator==(const SuperInt& left, const SuperInt& right) {
    return left.digits == right.digits;
}

bool operator!=(const SuperInt& left, const SuperInt& right) {
    return !(left == right);
}

bool operator<(const SuperInt& left, const SuperInt& right) {
    int leftLen = left.digits.size(), rightLen = right.digits.size();
    if (leftLen != rightLen) {
        if (leftLen > rightLen){
            return false;
        }
        else {
            return true;
        }
    }

    for(int i = leftLen; i >= 0; i--){
        if (left[i] < right[i]){
            return true;
        }
    }
    return false;
}

bool operator>(const SuperInt& left, const SuperInt& right) {
    int leftLen = left.digits.size(), rightLen = right.digits.size();
    if (leftLen != rightLen){
        if (rightLen > leftLen){
            return false;
        }
        return true;
    }

    for (int i = leftLen; i >)
}

bool operator>=(const SuperInt& left, const SuperInt& right) {
    return !(left < right);
}

bool operator<=(const SuperInt& left, const SuperInt& right) {
    return !(left > right);
}

//Power functions
SuperInt SuperInt::pow(SuperInt& sInt) {
    SuperInt temp = this->digits;
    for (SuperInt si = '0'; si < sInt; si++) {
        temp *= sInt;
    }
    return temp;
}

SuperInt SuperInt::pow(unsigned long long lInt) {
    SuperInt orig = lInt;
    SuperInt temp = lInt;
    for (SuperInt si = '0'; si < orig; si++) {
        temp *= orig;
    }
    return temp;
}

//Modulo
SuperInt& operator%=(SuperInt& a, const SuperInt& b) {
    if (b.Null())
        throw("Arithmetic Error: Division By 0");
    if (a < b) {
        return a;
    }
    if (a == b) {
        a = SuperInt();
        return a;
    }
    int i, lgcat = 0, cc;
    int n = a.digits.size(), m = b.digits.size();
    vector<int> cat(n, 0);
    SuperInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t; cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a = t;
    return a;
}

SuperInt operator%(const SuperInt& a, const SuperInt& b) {
    SuperInt temp;
    temp = a;
    temp %= b;
    return temp;
}

//Read and Write
ostream& operator<<(ostream& out, const SuperInt& a) {
    for (int i = a.digits.size() - 1; i >= 0; i--) {
        cout << (short)a.digits[i];
    }
    return cout;
}

istream& operator>>(istream& in, SuperInt& a) {
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}


