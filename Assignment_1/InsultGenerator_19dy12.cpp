/*
 * InsultGenerator.cpp
 *
 * 320 Assignment 1 
 * Dajung Yoon
 * 19dy12 Student #:20206993
 * 
 */
#include "InsultGenerator_19dy12.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//File exception class
FileException::FileException(const string& message) : message(message) {} 
string& FileException::what() {return message;}

//NumInsultsOutofBounds class
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message) {} 
string& NumInsultsOutOfBounds::what() {return message;} 

//Insult Generator class
InsultGenerator::InsultGenerator(){} 

/* This function initialize() is will open the file and read the
 * the contents of InsultsSource.txt
 * Exceptions : FileException
 * If the file cannot be read
 * 
 */
void InsultGenerator::initialize(){
	ifstream inFile;
	string line;
	inFile.open("InsultsSource.txt"); 
	if (inFile.fail()) {
			throw FileException("File can not be read!");
		} 
	
	//start the count to analyze the amount of words
	//so we are able to check the amount of insults for testing
	int count(0);

	while (inFile >> line){     
				count++;
				if (count==1){
					insult1.push_back(line);
				}
				if (count==2){
					insult2.push_back(line);  
				}
				if (count==3){
					insult3.push_back(line);  
					count=0;
				}
	}
	inFile.close();
} 

/*
 * This function will generate a random number 
 * To use when generating an insult
 * Return : num 
 * No exceptions
 */
int InsultGenerator::randomNum(){
	int num = rand() % 49; 
	return num;
} 

/*
 * This function will be creating the insult with the addition of Thou and !
 * Returns: Insult
 */
string InsultGenerator::talkToMe() {
	string insult;
	int num1 = randomNum();
	int num2 = randomNum();
	int num3 = randomNum();
	insult = "Thou " + insult1[num1] + " " + insult2[num2] + " " + insult3[num3] + "!";  
	return insult;
} 

/*
 * This function will create the set of insults into a new vector
 * Returns : insults
 */
vector<string> InsultGenerator::generate(int numInsults){
	if (numInsults < 1 || numInsults > 10000){
		throw NumInsultsOutOfBounds("This is not valid number of insults! Must be between 1 and 10000");
	} 

	set<string> setOfInsults;

	string insult;

	//make sure it is in the set of insults
	while (numInsults > setOfInsults.size()){    
		insult = string(talkToMe());
		setOfInsults.insert(insult);
	} 
	vector<string> insults;

	//make the right order of insults
	copy(setOfInsults.begin(), setOfInsults.end(), back_inserter(insults));
	return insults;
}

//This function will save the insults into a vector that can be rewritten 
//in a source file. 
void InsultGenerator::generateAndSave(string fileName, int numInsults){
	
	int lineNumber=0;

	vector<string> insultVector = generate(numInsults); 

	//make new .txt file
	ofstream outFile(fileName.c_str());   

	if (outFile.fail()){
		throw FileException("File can not be written");  
	} 

	while(lineNumber < numInsults){
		outFile << insultVector[lineNumber] << endl;
		lineNumber++;
	}
	outFile.close();
}