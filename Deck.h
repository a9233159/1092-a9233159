#pragma once
#include<iostream>
#include <string>                                            
#include <time.h>								// header files include time.h for randomizing
#include "Card.h"
using namespace std;

class deck                                      // creates class deck
{
private:                                        // create private variables
	const int numberOfCards = 52;
	card cardDeck[52];
	int placeInDeck = 0;

public:                                         // create public variables
	deck();
	~deck();

	void setPlaceInDeck(int aPlace);
	int getPlaceInDeck();

	void getDeck(card aDeck[], int deckSize);
	void showDeck();
	void shuffleDeck();
	card dealCard();
};