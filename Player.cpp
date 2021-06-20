#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <string>

player::player()
{

}
player::~player()
{

}

void player::setName(string aString)								  // lines 16 - 31 getters and setters for player variables
{
	name = " ";
}
string player::getName()
{
	return name;
}
int player::getNumberOfCardsInHand()              
{
	return numberOfCardsInHand;
}
int player::getValue()
{
	return value;
}

void player::getCard(card aCard)                                      // gives player card and increments the number of cards in hand
{
	cout << aCard.getFace() << " of " << aCard.getSuit() << endl;
	hand[numberOfCardsInHand] = aCard;
	numberOfCardsInHand++;
}
void player::showYourHand()                                            // shows what they have in hand
{
	for (int i = 0; i < numberOfCardsInHand; i++)
	{
		cout << hand[i].getFace() << " of " << hand[i].getSuit() << endl;
	}
}
int player::getScore()                                                 // determines scores of individual players
{
	int handScore = 0;

	for (int i = 0; i < numberOfCardsInHand; i++)
	{
		handScore += hand[i].getValue();
	}

	return handScore;
}