/*
#include <math.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#ifndef BIGINT_H
#define BIGINT_H

class BigInt {
	string digits;
public:

	//Constructors:
	BigInt(unsigned long long n = 0);
	BigInt(string&);
	BigInt(const char*);
	BigInt(const BigInt&);
	BigInt(BigInt&&);

	//Getter and Setter
	string getDigits();
	bool setDigits(); // dogots

	//Helper Functions:
	friend void divide_by_2(BigInt& a);
	friend bool Null(const BigInt&);
	friend int Length(const BigInt&);
	int operator[](const int)const;
	*/
	/* * * * Operator Overloading * * * */
	/*
	//Assignment
	BigInt& operator=(const BigInt&);
	BigInt& operator=(const int&);

	//Post/Pre - Incrementation
	BigInt& operator++();
	BigInt operator++(int temp);
	BigInt& operator--();
	BigInt operator--(int temp);

	//Addition and Subtraction
	friend BigInt& operator+=(BigInt&, const BigInt&);
	friend BigInt operator+(const BigInt&, const BigInt&);
	friend BigInt operator-(const BigInt&, const BigInt&);
	friend BigInt& operator-=(BigInt&, const BigInt&);

	//Comparison operators
	friend bool operator==(const BigInt&, const BigInt&);
	friend bool operator!=(const BigInt&, const BigInt&);

	friend bool operator>(const BigInt&, const BigInt&);
	friend bool operator>=(const BigInt&, const BigInt&);
	friend bool operator<(const BigInt&, const BigInt&);
	friend bool operator<=(const BigInt&, const BigInt&);

	//Multiplication and Division
	friend BigInt& operator*=(BigInt&, const BigInt&);
	friend BigInt operator*(const BigInt&, const BigInt&);
	friend BigInt& operator/=(BigInt&, const BigInt&);
	friend BigInt operator/(const BigInt&, const BigInt&);

	//Modulo
	friend BigInt operator%(const BigInt&, const BigInt&);
	friend BigInt& operator%=(BigInt&, const BigInt&);

	//Power Function 
	friend BigInt& operator^=(BigInt&, const BigInt&);
	friend BigInt operator^(BigInt&, const BigInt&);  

	//Read and Write
	friend ostream& operator<<(ostream&, const BigInt&);
	friend istream& operator>>(istream&, BigInt&);
};

#endif
*/