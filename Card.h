#pragma once 
#include <string>
using namespace std;

class card                                    // sets up class for card
{
private:									  // create private variables
	string face = " ";
	string suit = " ";
	int value = 0;

public:									      // create public variables
	card();
	~card();

	void setFace(string aFace);
	void setSuit(string aSuit);
	void setValue(int aValue);

	string getFace();
	string getSuit();
	int getValue();
};