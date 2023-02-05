/*
 * JumblePuzzle.h
 *
 *  Created on: Nov 10, 2016
 *      Author: Ramy Ayash - 13ra24 - 10130200
 *      This is Assignment 4, Course CISC 320
 *      The JumblePuzzle is a 2D matrix containing a word inputted by the user that is to be hidden
 *      The JumblePuzzle is stored on the heap, and is deleted after the user has figured out the location of the word
 *      The BadJumbleException class is included and provides customized error messages to the users
 */
#include<iostream>
#include<exception>
#include<string>
#include<stdlib.h>
using namespace std;
typedef char* charArrayPtr;

class JumblePuzzle {
	public:
		JumblePuzzle(const string& toHide, const string& diff); //Constructor that takes a word and a difficulty, Takes 2 strings: Word to be hidden and Difficulty
		JumblePuzzle(const JumblePuzzle& right); //Copy Constructor
		~JumblePuzzle(); //Destructor, gets rid of the matrix object on the heap when the player has guessed the word or terminated the program
		JumblePuzzle& operator=(const JumblePuzzle& right); //Assignment operator overloading
		charArrayPtr* getJumble() const; //Getter for the matrix
		int getSize() const; //Getter for the size of the matrix
		int getRowPos() const; //Gets the row position, mostly to check if the user is correct
		int getColPos() const; //Gets the column position, mostly to check if the user is correct
		char getDirection() const; //Fetches the direction of the rest of the word from the user
	private:
		int row;
		int col;
		int len;
		char direction;
		charArrayPtr* matrix;
};

class BadJumbleException {
public:
	BadJumbleException(const string&); //Gives a customized message for Jumble Exceptions
	string& what();
private:
	string message;
};