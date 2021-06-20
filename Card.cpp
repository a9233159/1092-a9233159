#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include <iostream> 
using namespace std;

card::card()
{

}
card::~card()
{

}

void card::setFace(string aFace)          // lines 16 - 40, getters and setters for variables in Card.h
{
	face = aFace;
}
void card::setSuit(string aSuit)
{
	suit = aSuit;
}
void card::setValue(int aValue)
{
	value = aValue;
}

string card::getFace()                
{
	return face;
}
string card::getSuit()
{
	return suit;
}
int card::getValue()
{
	return value;
}