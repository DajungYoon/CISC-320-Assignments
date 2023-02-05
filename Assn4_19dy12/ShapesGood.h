#ifndef CISC320ASSIGNMENT4
#define CISC320ASSIGNMENT4

#include "string"
#include <ostream>

using namespace  std; 

//BASICS
class Shape{
public:
    //constructor
    Shape(int len, int wid);  
    //getter
    int getLength() const;     
    //getter
    int getWidth() const;     
    //drawing shapes
    virtual void draw() =0;   
    //destructor
    virtual ~Shape(); 

private:
    int len; 
    int wid;  
};

class Fillable{
public:
    Fillable (string fillableColour);    
    string getFilledColour() const;     
    virtual ~Fillable();      

private:
    string fillableColour;  

};

class Text{
public:
    Text(string text); 
    string getText() const; 
    virtual ~Text(); 
private:
    string text; 

};

//---------------------------------------------------------------------------------------
//SHAPES

class Square: public Shape{
public:
    Square(int len, int wid, string outlineColour); 
    virtual void draw();
    string getOutlineColour() const;  
    virtual ~Square();
private:
    string outlineColour;
};

class FilledSquare: public Square, public Fillable{
public:
    FilledSquare(int len, int wid, string outlineColour, string filledColour);
    virtual void draw();
    virtual ~FilledSquare();
private:
   
};

class FilledTextSquare: public Square, public Fillable, public Text{
public:
    FilledTextSquare(int len, int wid, string outlineColour, string filledColour, string text); 
    virtual void draw();
    virtual ~FilledTextSquare();
private:
   
};

//---------------------------------------------------------------------------------------

class Circle: public Shape{
public:
    Circle(int len, int wid, string outlineColour); 
    virtual void draw();
    string getOutlineColour() const;
    virtual ~Circle();
private:
    string outlineColour;
};

class FilledCircle: public Circle, public Fillable{
public:
    FilledCircle(int len, int wid, string outlineColour, string filledColour); 
    virtual void draw();
    virtual ~FilledCircle();
private:
 
};

//---------------------------------------------------------------------------------------

class Arc: public Shape{
public:
    Arc(int len, int wid, string outlineColour);
    virtual void draw();
    string getOutlineColour() const;  
    virtual ~Arc(); 
private:
    string outlineColour;
};

#endif //CISC320ASSIGNMENT4