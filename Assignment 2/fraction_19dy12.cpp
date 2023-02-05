/*
 * fraction_19dy12.cpp
 *
 * 320 Assignment 2 
 * Dajung Yoon
 * 19dy12 Student #:20206993
 * 
 */

#include <iostream>
#include<cmath>
#include<string>
using namespace std;

#include "fraction_19dy12.h"

//Initializing error class
FractionException::FractionException(const string& message) : message(message) {} 
string& FractionException::what() {return message;}

//Constructor #1 with no parameters
Fraction::Fraction(){
	num=0;
	den=1;
}
//Constructor #2 with one parameter
Fraction::Fraction(int n){
	num=n;
	den=1;
}

int GCD(int n,int m);

//Constructor #3 with two parameters
Fraction::Fraction(int n,int m){
	if(m==0){
		//if the user attempts to create a Fraction with a zero value denominator
		//throw an exception
		throw FractionException("0/1");
	}

	int gcd=GCD(n,m);

	//normalize a fraction to know the GCD of the two numbers
	if(m<0){
		num=-n/gcd;
		den=-m/gcd;
	}
	else {
		num=n/gcd;
		den=m/gcd;
	}
}

int GCD(int n,int m){
	/*
	 * Given Recursive function
	 * Returns: the denom, GCD, or GCD(denom,num%denom)
	 */
	n=abs(n);
	m=abs(m);

	if(m<=n && n%m==0){
		return m;}
	else if(n<m){
		return GCD(m,n);}
	else {
		return GCD(m,n%m);}
}

int Fraction::numerator() const{
	/*
	 * This function will return the numerator of a function
	 */
	return num;
}

int Fraction::denominator() const{
	/*
	 * This function will return the denominator of a function
	 */
	return den;
}

/********************************************************/

//UNARY OPERATORS
Fraction Fraction::operator-(){

	//the negative sign on the numerator will turn the function negative
	return Fraction(-num,den);
}

Fraction Fraction::operator++(){
	//pre-increment
	*this=*this+1;
	return *this;
}

Fraction Fraction::operator++(int){
	//post-increment
	Fraction temp=*this;
	*this=*this+1;
	return temp;
}
/********************************************************/

//BINARY OPERATOR with assignment
void Fraction::operator+=(const Fraction& LHS){
	//addition and assignment
	*this=*this+LHS;
}

/********************************************************/
//Binary operators
Fraction operator+(const Fraction& frac1, const Fraction& frac2){
	//the numberator will be the sum of the fraction
	//the denominator will be the sum of the denominators
	int totalNumerator=(frac1.num*frac2.den)+(frac2.num*frac1.den);
	int denominator=frac1.den*frac2.den;
	return 	Fraction(totalNumerator,denominator);
}

Fraction operator-(const Fraction& frac1, const Fraction& frac2){
	//the numberator will be the difference of the fraction
	//the denominator will be the difference of the denominators
	int totalNumerator=(frac1.num*frac2.den)-(frac2.num*frac1.den);
	int denominator=frac1.den*frac2.den;
	return 	Fraction(totalNumerator,denominator);
}

Fraction operator*(const Fraction& frac1, const Fraction& frac2){
	//The numerator multiplied with the second numerator
	//The denominator multiplied with the second denominator
	int totalNumerator=frac1.num*frac2.num;
	int denominator=frac1.den*frac2.den;
	return 	Fraction(totalNumerator,denominator);
}


Fraction operator/(const Fraction& frac1, const Fraction& frac2){
	//num of the first fraction * by the denominator of the second fraction
	//vice versa for quotient denominator
	int totalNumerator=frac1.num*frac2.den;
	int denominator=frac1.den*frac2.num;
	return 	Fraction(totalNumerator,denominator);
}

ostream& operator<<(ostream& os,const Fraction& frac){
	//make sure to put it in the form of a fraction
	os<<frac.num<<"/"<<frac.den;
	return os;
}

istream& operator>>(istream &input,Fraction& frac){
	char nextFrac;
	cin>>frac.num;

	if(frac.num==0){
		//if the numerator is 0, then make the fraction 0/1 (invalid)
		frac.den=1;
		return input;
	}
	else{
	cin>>nextFrac>>frac.den;
	}
	return input;
}

/********************************************************/

//comparison operators
//for <, <=, >, and >=, the math will multiply the num and denom of the function called.
//Compare the two numbers and return true if it satisfies

//For != amd ==, the function just needs to see if both of the numerators and denominator
// for each of the values are equal are not equal to eachother
bool operator<(const Fraction& LHS, const Fraction& RHS){
	if((LHS.numerator()*RHS.denominator())<(LHS.denominator()*RHS.numerator())) {
		return true;
	}
	return false;
}

bool operator<=(const Fraction& LHS, const Fraction& RHS){
	if((LHS.numerator()*RHS.denominator())<=(LHS.denominator()*RHS.numerator())){ 
		return true;
	}
	return false;
}

bool operator==(const Fraction& LHS, const Fraction& RHS){
	if ((LHS.numerator()==RHS.numerator()) && (LHS.denominator()==RHS.denominator())) {
		return true;
	}
	return false;
}

bool operator!=(const Fraction& LHS, const Fraction& RHS){
	if((LHS.numerator()!=RHS.numerator()) || (LHS.denominator()!=RHS.denominator())) {
		return true;
	}
	return false;
}

bool operator>(const Fraction& LHS, const Fraction& RHS){
	if((LHS.numerator()*RHS.denominator())>(LHS.denominator()*RHS.numerator())){
		return true;
	}
	return false;
}

bool operator>=(const Fraction& LHS, const Fraction& RHS){
	if((LHS.numerator()*RHS.denominator())>=(LHS.denominator()*RHS.numerator())){
		return true;
	} 
	return false;
}

//end file