#include "string"
#include "ShapesGood.h"
#include <ostream>
#include <iostream>

using namespace std;

//getter methods
int Shape::getLength() const {
    return this-> len;
}
int Shape::getWidth() const {
    return this->wid;
}
string Fillable::getFilledColour() const {
    return this-> fillableColour;
}
string Text::getText() const {
    return this-> text;
}
string Square::getOutlineColour() const {
    return this->outlineColour;
}
string Circle::getOutlineColour() const{
    return this->outlineColour;
}
string Arc::getOutlineColour() const { 
    return this->outlineColour;
}

//destructors
Shape::~Shape() {}
Fillable::~Fillable() {}
Text::~Text() {}
Square::~Square(){}
FilledSquare::~FilledSquare(){}
FilledTextSquare::~FilledTextSquare(){}
Circle::~Circle(){}
FilledCircle::~FilledCircle(){}
Arc::~Arc(){}

//Parent Constructors
Shape::Shape(int len, int wid) {
    this->len = len;
    this->wid = wid;
}
Fillable::Fillable(string colour) {
    this->fillableColour = colour;
}
Text::Text(string text) {
    this->text = text;
}

//Squares:
Square::Square(int len, int wid, string outlineColour): Shape(len, wid){
    this->outlineColour = outlineColour;
}

void Square::draw() {
    cout << "Drawing a square, length: " << getLength() << " and width: " << getWidth() <<endl;
}

//Filled Squares:
FilledSquare::FilledSquare(int len, int wid, string outlineColour, string fillableColour): Square(len,wid, outlineColour), Fillable(fillableColour)  {}

 void FilledSquare::draw() {
    cout << "Drawing a filled square, length:" << getLength() << " width: " << getWidth() << " outline: "<< getOutlineColour() << " and fill color: " << getFilledColour() << endl;

}

//Filled Text Squares:
FilledTextSquare::FilledTextSquare(int len, int wid, string outlineColour, string fillableColour, string text): Square(len, wid, outlineColour), Fillable(fillableColour), Text(text) {}

void FilledTextSquare::draw(){
    cout << "Drawing a filled fext square,  length: " << getLength() << " width: " << getWidth() << " outline colour: "<< getOutlineColour()<< "  fill colour: " << getFilledColour() << " and text: " << getText() << endl;

}

//Circle:
Circle::Circle(int len, int wid, string outlineColour): Shape(len, wid) {
    this->outlineColour = outlineColour;
}
void Circle::draw(){
cout << "Drawing a circle, length: " << getLength() << " width: " << getWidth() << " and outline colour: " << getOutlineColour() <<endl;
}

//Filled Circle:
FilledCircle::FilledCircle(int len, int wid, string outlineColour, string fillableColour): Circle(len, wid, outlineColour), Fillable(fillableColour) {}

void FilledCircle::draw() {
    cout << "Drawing a circle with length " << getLength() << " width: " << getWidth() << " outline colour: " << getOutlineColour() << " and filled colour: " << getFilledColour() <<endl;

}

//Arc:
Arc::Arc(int len, int wid, string outlineColour): Shape(len, wid){
    this->outlineColour = outlineColour;
}

void Arc::draw() {
 cout << "Drawing an arc, length: " << getLength() << " width: " << getWidth() << " and outline colour: " << getOutlineColour()<<endl;
}