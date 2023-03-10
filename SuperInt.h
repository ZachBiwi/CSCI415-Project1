#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#ifndef SUPERINT_H
#define SUPERINT_H
using namespace std;

class SuperInt{
private:
    string digits;

public:
    
    //Constructors:
	SuperInt(unsigned long long n = 0);
	SuperInt(const string&);
	SuperInt(const char*);
    SuperInt(const SuperInt&);
    SuperInt(SuperInt&);

    //Getter and Setter
	string getDigits();
	bool setDigits(string&); // dogots

    //Helper Functions:
	bool Null();
    bool Null() const;
	int Length() const;
	int operator[](const int)const;
    SuperInt pow(SuperInt&);
    SuperInt pow(unsigned long long);

    /* * * * Operator Overloading * * * */

	//Assignment
	SuperInt& operator=(const SuperInt&);
	SuperInt& operator=(const unsigned long long &);

	//Post/Pre - Incrementation
	friend SuperInt& operator++(SuperInt&, int);
	friend SuperInt& operator--(SuperInt&, int);

    //Addition and Subtraction
	friend SuperInt& operator+=(SuperInt, const SuperInt&);
	friend SuperInt operator+(const SuperInt&, const SuperInt&);
	friend SuperInt operator-(const SuperInt&, const SuperInt&);
	friend SuperInt& operator-=(SuperInt, const SuperInt&);

	//Comparison operators
	friend bool operator==(const SuperInt&, const SuperInt&);
	friend bool operator!=(const SuperInt&, const SuperInt&);
	friend bool operator>(const SuperInt&, const SuperInt&);
	friend bool operator>=(const SuperInt&, const SuperInt&);
	friend bool operator<(const SuperInt&, const SuperInt&);
	friend bool operator<=(const SuperInt&, const SuperInt&);

    //Multiplication and Division
	friend SuperInt& operator*=(SuperInt&, const SuperInt&);
	friend SuperInt operator*(const SuperInt&, const SuperInt&);
	friend SuperInt& operator/=(SuperInt&, const SuperInt&);
	friend SuperInt operator/(const SuperInt&, const SuperInt&);

	//Modulo
	friend SuperInt operator%(const SuperInt&, const SuperInt&);
	friend SuperInt& operator%=(SuperInt&, const SuperInt&);

	//Read and Write
	friend ostream& operator<<(ostream&, const SuperInt&);
	friend istream& operator>>(istream&, SuperInt&);

};

#endif