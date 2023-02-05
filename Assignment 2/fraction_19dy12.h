/*
 * fraction_19dy12.h
 *
 * 320 Assignment 2 
 * Dajung Yoon
 * 19dy12 Student #:20206993
 * 
 */

//start guard
#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>

class Fraction{
public:

	//Given three constructors
	//CONSTRUCTORS
	Fraction();
	Fraction(int n);
	Fraction(int n,int d);

	//getter function
	int numerator() const;
	//getter function
	int denominator() const;

	//UNARY OPERATORS
	Fraction operator-();
	Fraction operator++();
	Fraction operator++(int);
	
	//BINARY OPERATOR with assignment
	void operator+=(const Fraction& LHS);

private:
	//private variables for the numerator and denominator
	int num;
	int den;

//Binary operator
//this is calling to the Fraction constructor with only one parameter
friend Fraction operator-(const Fraction& num);

//Given in the assignment instructions
//Binary operators
friend Fraction operator+(const Fraction& LHS, const Fraction& RHS);
friend Fraction operator-(const Fraction& LHS, const Fraction& RHS);
friend Fraction operator*(const Fraction& LHS, const Fraction& RHS);
friend Fraction operator/(const Fraction& LHS, const Fraction& RHS);

friend ostream& operator<<(ostream& out, const Fraction& num);
friend istream& operator>>(istream& input, Fraction& inp);

//comparison operators
friend bool operator<(const Fraction& LHS, const Fraction& RHS);
friend bool operator<=(const Fraction& LHS, const Fraction& RHS);
friend bool operator==(const Fraction& LHS, const Fraction& RHS);
friend bool operator!=(const Fraction& LHS, const Fraction& RHS);
friend bool operator>=(const Fraction& LHS, const Fraction& RHS);
friend bool operator>(const Fraction& LHS, const Fraction& RHS);

};

// This class throws an exception 
//if the user attempts to create a Fraction with a zero value denominator
class FractionException{
public:
	FractionException(const string& message);
	string& what();
private:
	string message;
};


#endif //end guard