/*
 * jumble_19dy12.h
 *
 * 320 Assignment 3
 * Dajung Yoon
 * 19dy12 Student #:20206993
 * 
 */

#ifndef JUMBLE_H_
#define JUMBLE_H_

#include <string>

using namespace std;

typedef char* charArrayPtr;

class JumblePuzzle
{
	public:
		//Constructors
		JumblePuzzle(const string&, const string&);
		JumblePuzzle(const JumblePuzzle&);

		//Destructor
		~JumblePuzzle();

		//Overloading the assignment operator
		JumblePuzzle& operator=(const JumblePuzzle&);

		//Accessors
		charArrayPtr* getJumble() const;
		int getSize() const;
		int getRowPos() const;
		int getColPos() const;
		char getDirection() const;

	private:
		//these variables are to be used for the dimensions of the jumble
		int size;
		int row;
		int col;
		char direction;
		charArrayPtr* jumble;
};

class BadJumbleException
{
	//Throw an error if there is something wrong about any input of the hidden word from the player
	public:
		BadJumbleException(const string&); 							
		string& what();												

	private:
		string message;
};

#endif 