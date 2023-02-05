/*
 * JumblePuzzle.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: ramy
 */

#include "JumblePuzzle.h"
#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
using namespace std;

JumblePuzzle::JumblePuzzle(const string& toHide, const string& diff) {
	len = toHide.length();
	if(len < 3 || len > 10) //Checks to see that the word is not too short or too long
		throw BadJumbleException("Length of word cannot be less than 3 or more than 18");

	if (diff == "easy") {len *= 2;}
	else if (diff == "medium") {len *=3;}
	else if(diff == "hard") {len *= 4;}
	else
		throw BadJumbleException("Difficulty must be easy, medium, or hard");

	matrix = new char*[len]; //Making a new Matrix

	for (int i = 0; i < len; i++)
		matrix[i] = new char[len]; //Making the Matrix 2D, Adding columns

	const char* letters = "abcdefghijklmnopqrstuvwxyz"; //Available letters

	srand(time(NULL));

	for(int i = 0; i< len; i++)
		for(int j = 0; j < len; j++)
			matrix[i][j] = (char) letters[rand() % 25];

	row = rand() % len;
	col = rand() % len;

	matrix[row][col] = toHide.at(0);
	const char* dir = "nesw";
	bool placed = false;

	while(!placed){
		// Pick a random direction
				direction = dir [rand() % 4];

				if (direction == 'n'){ //Moving up
					for (int i = 1; i < toHide.length(); i++)
					{
						// Out of bounds
						if ((row-i) < 0)
							break;
						else if (i == (toHide.length() - 1)){ // last letter

							matrix[row-i][col] = toHide.at(i);
							placed = 1;
						}
						else
							matrix[row-i][col] = toHide.at(i);
					}
				}
				else if (direction == 'e'){ // Moving right
					for (int i = 1; i < toHide.length(); i++){
						if ((col+i) > (toHide.length()-1))
							break;
						else if (i == (toHide.length() - 1)){
							matrix[row][col+i] = toHide.at(i);
							placed = 1;
						}
						else
							matrix[row][col+i] = toHide.at(i);
					}
				}
				else if (direction == 's'){
					// Going down
					for (int i = 1; i < toHide.length(); i++){
						if ((row+i) > (toHide.length()-1))
							break;
						else if (i == (toHide.length() - 1)){
							matrix[row+i][col] = toHide.at(i);
							placed = 1;
						}
						else
							matrix[row+i][col] = toHide.at(i);
					}
				}
				else{ //Going left
					for (int i = 1; i < toHide.length(); i++){
						if ( (col-i) < 0 )
							break;
						else if (i == (toHide.length() - 1)){
							matrix[row][col-i] = toHide.at(i);
							placed = 1;
						}
						else
							matrix[row][col-i] = toHide.at(i);
					}
				}
			}
	}

JumblePuzzle::JumblePuzzle(const JumblePuzzle& right){
	len = right.getSize();
	row = right.getRowPos();
	col = right.getColPos();
	direction = right.getDirection();
	matrix = new char*[len];

	for (int i = 0; i < len; i++)
		matrix[i] = new char[len];

	charArrayPtr* rightMatrix = right.getJumble();

	for (int i = 0; i < len; i++){
		for (int j = 0; j < len; j++)
			matrix[i][j] = rightMatrix[i][j];
	}
}

int JumblePuzzle::getSize() const { return len; }
int JumblePuzzle::getRowPos() const { return row; }
int JumblePuzzle::getColPos() const { return col; }
char JumblePuzzle::getDirection() const { return direction; }

JumblePuzzle::~JumblePuzzle() {
	for(int i = 0; i < len; i++)
		delete matrix[i];
	delete[] matrix;
}

JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& right){
	if(this != &right)
	{
		row = right.getRowPos();
		col = right.getColPos();
		direction = right.getDirection();
		len = right.getSize();

		for(int i = 0; i < len; i++)
			delete[] matrix[i];
		delete[] matrix;
		matrix = new char*[len];
		for(int i = 0; i < len; i++)
			matrix[i] = new char[len];

		charArrayPtr* rightJumble = right.getJumble();

		for (int i = 0; i < len; i++){
			for(int j = 0; j < len; j++)
				matrix[i][j] = rightJumble[i][j];
		}
	}
	return *this;
}

charArrayPtr* JumblePuzzle::getJumble() const{
	charArrayPtr* newMatrix = new char*[len];

	for (int i = 0; i < len; i++)
		newMatrix[i] = new char[len];

	for (int i = 0; i < len; i++){
		for (int j = 0; j < len; j++)
			newMatrix[i][j] = matrix[i][j];
	}
	return newMatrix;
}

BadJumbleException::BadJumbleException(const string& e) : message(e){ }
string& BadJumbleException::what() { return message; }