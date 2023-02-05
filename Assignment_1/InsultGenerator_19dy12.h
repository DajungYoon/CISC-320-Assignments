/*
 * InsultGenerator.h
 *
 * 320 Assignment 1 
 * Dajung Yoon
 * 19dy12 Student #:20206993
 * 
 */
#ifndef INSULTGENERATOR_H_
#define INSULTGENERATOR_H_

//additions libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


//This function is an exception class
class FileException{
public:
		//reference to message
		FileException(const string& message);
		string& what();
private:
		//Read the messages
		string message;
}; 

//This function is an exception class
class NumInsultsOutOfBounds{
public:
		//reference to message
		NumInsultsOutOfBounds(const string& message);
		string& what();
private:
		//Read the messages	
		string message;
}; 

//This is the InsultGenerator class
class InsultGenerator{
public:
		//constructor
		InsultGenerator();

		//Read the contents of the file
		void initialize();	

		//Put together the insults								
		string talkToMe();

		//Put insults into a vector										
		vector<string> generate (const int numInsults);

		//Generate the insults, and save them to a new .txt file			
		void generateAndSave(string fileName, int numInsults);	
private:
		//generate a random number for talkToMe()
		int randomNum();	

		//the three columns of insults									
		vector<string> insult1;
		vector<string> insult2;
		vector<string> insult3;
		set<string> setOfInsults;
}; 


#endif