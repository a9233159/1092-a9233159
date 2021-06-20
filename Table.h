#pragma once
#include <iostream>
#include <string>
#include "Deck.h"
#include "Player.h"
#include "Dealer.h" 
using namespace std;

class table                        // sets up class for table
{
private:						   // create private variables
	player thePlayers[4];
	dealer aDealer;
	deck aDeck;

public:							   // create public variables
	table();
	~table();

	void showCardDeck();
	void playBlackJack();		   // gameplay
	void dealBlackJack();
	void showPlayerHands();
	void hitHand();                // hit or hold
	void getWinners();
};