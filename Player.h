#pragma once
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

class player                                        // sets up class for player
{
private: 
	string name = "";
	card hand[10];
	int numberOfCardsInHand = 0;
	int value = 0;

public:												// create public variables
	player();
	~player();

	void setName(string aString);
	string getName();
	int getNumberOfCardsInHand();
	int getValue();

	void getCard(card aCard);
	void showYourHand();
	int getScore();
};