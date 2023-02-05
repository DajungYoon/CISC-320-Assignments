/*
 * jumble_19dy12.cpp
 *
 * 320 Assignment 3 
 * Dajung Yoon
 * 19dy12 Student #:20206993
 * 
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jumble_19dy12.h"

using namespace std;

// Constructors
JumblePuzzle::JumblePuzzle(const string& toHide, const string& difficulty)
{
	size = toHide.length();

	//Throw an exception if the size is not between 3 and 10
	//10 is larger than the square
	if (size < 3 || size > 10)
	{
		throw BadJumbleException("Invalid length of hidden word. Must be between 3 and 10 characters.");
	}

	if (difficulty == "easy")
		size *= 2;
	else if (difficulty == "medium")
		size *= 3;
	else if (difficulty == "hard")
		size *= 4;
	else
		throw BadJumbleException("Invalid difficulty. Must be \"easy\", \"medium\", or \"hard\".");

	jumble = new char*[size];

	// arrays on the heap
	for (int i = 0; i < size; i++)
		jumble[i] = new char[size];

	const char* letters = "abcdefghijklmnopqrstuvwxyz";

	

	srand(time(NULL));
	//we need to fill the heap with random letters
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			jumble[i][j] = (char) letters[rand() % 25];

	// Hide the word at a random row and column
	row = rand() % size;
	col = rand() % size;

	// Put the first letter down
	jumble[row][col] = toHide.at(0);

	const char* dir = "nesw";
	bool placedWord = 0;

	while (!placedWord)
	{
		// Pick a random direction
		direction = dir [rand() % 4];

		if (direction == 'n')
		{
			// Place the remaining characters going upwards
			for (int i = 1; i < toHide.length(); i++)
			{
				//if the word does not fit going upwards, then try another direction
				if ((row-i) < 0)
					break;
				else if (i == (toHide.length() - 1))
				{
					jumble[row-i][col] = toHide.at(i);
					placedWord = 1;
				}
				else
					jumble[row-i][col] = toHide.at(i);
			}
		}
		//same thing for east, south, and west
		else if (direction == 'e')
		{
			for (int i = 1; i < toHide.length(); i++)
			{
				if ((col+i) > (size-1))
					break;
				else if (i == (toHide.length() - 1))
				{
					jumble[row][col+i] = toHide.at(i);
					placedWord = 1;
				}
				else
					jumble[row][col+i] = toHide.at(i);
			}
		}
		else if (direction == 's')
		{
			// Going downwards
			for (int i = 1; i < toHide.length(); i++)
			{
				if ((row+i) > (size-1))
					break;
				else if (i == (toHide.length() - 1))
				{
					jumble[row+i][col] = toHide.at(i);
					placedWord = 1;
				}
				else
					jumble[row+i][col] = toHide.at(i);
			}
		}
		else // direction == 'w'
		{
			// Going left (backwards)
			for (int i = 1; i < toHide.length(); i++)
			{
				if ( (col-i) < 0 )
					break;
				else if (i == (toHide.length() - 1))
				{
					jumble[row][col-i] = toHide.at(i);
					placedWord = 1;
				}
				else
					jumble[row][col-i] = toHide.at(i);
			}
		}
	}
}

// Copy Constructor
JumblePuzzle::JumblePuzzle(const JumblePuzzle& right)
{
	size = right.getSize();
	row = right.getRowPos();
	col = right.getColPos();
	direction = right.getDirection();

	jumble = new char*[size];

	for (int i = 0; i < size; i++)
		jumble[i] = new char[size];

	charArrayPtr* rightJumble = right.getJumble();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			jumble[i][j] = rightJumble[i][j];
	}
}

JumblePuzzle::~JumblePuzzle()
{
	for (int i = 0; i < size; i++)
		delete jumble[i];

	delete[] jumble;
}

//Overloading!!!!
JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& right)
{
	if (this != &right)
	{
		row = right.getRowPos();
		col = right.getColPos();
		direction = right.getDirection();
		size = right.getSize();

		//old jumble has to be deleted
		for (int i = 0; i < size; i++)
			delete[] jumble[i];
		delete[] jumble;

		jumble = new char*[size];

		// Create individual arrays on the heap
		for (int i = 0; i < size; i++)
			jumble[i] = new char[size];

		charArrayPtr* rightJumble = right.getJumble();

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				jumble[i][j] = rightJumble[i][j];
		}

	}
	return *this;
}

charArrayPtr* JumblePuzzle::getJumble() const
{
	charArrayPtr* newJumble = new char*[size];

	for (int i = 0; i < size; i++)
		newJumble[i] = new char[size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			newJumble[i][j] = jumble[i][j];
	}

	return newJumble;
}

int JumblePuzzle::getSize() const { return size; }
int JumblePuzzle::getRowPos() const { return row; }
int JumblePuzzle::getColPos() const { return col; }
char JumblePuzzle::getDirection() const { return direction; }

// BadJumbleException implementation
BadJumbleException::BadJumbleException(const string& m) : message(m) { }
string& BadJumbleException::what() { return message; }
