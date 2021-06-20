#include "Deck.h"
#include "Card.h"
#include <iostream> 

deck::deck()
{
	getDeck(cardDeck, numberOfCards);                                   // constuctor for getDeck to include card deck and number of cards
}
deck::~deck()
{

}

void deck::setPlaceInDeck(int aPlace)
{
	placeInDeck = aPlace;
}
int deck::getPlaceInDeck()                             
{
	return placeInDeck;
}

void deck::getDeck(card aDeck[], int deckSize)                          // lines 23 - 57 set up the card deck to include faces, suits, and values
{
	string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	int numberSuits = 4;
	string faces[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	int numFaces = 13;
	int aSuit = 0;
	int aFace = 0;

	for (int i = 0; i < deckSize; i++)
	{
		aDeck[i].setFace(faces[aFace]);
		aDeck[i].setSuit(suits[aSuit]);

		if (aFace < 10)
		{
			aDeck[i].setValue(aFace + 1);
		}
		else
		{
			aDeck[i].setValue(+10);
		}

		aSuit++;
		if (aSuit > 3)
		{
			aSuit = 0;
			aFace++;
		}
		if (aSuit > 12)
		{
			aFace = 0;
		}
	}
}
void deck::showDeck()                                                   // lines 58 - 64 show the deck so we can see all cards
{
	for (int i = 0; i < 52; i++)
	{
		cout << cardDeck[i].getFace() << " of " << cardDeck[i].getSuit() << endl;
	}
}
void deck::shuffleDeck()                                                // lines 65 - 76 shuffle the deck
{
	srand(time(0));

	cout << endl << "Shuffling....." << endl << endl << endl;

	for (int i = 0; i < 52; i++)
	{
		int r = i + (rand() % (52 - i));
		swap(cardDeck[i], cardDeck[r]);
	}
}
card deck::dealCard()                                                   // lines 77 - 83 deal card and uses code from Card.h
{
	card aCard = cardDeck[placeInDeck];
	placeInDeck++;

	return aCard;
}