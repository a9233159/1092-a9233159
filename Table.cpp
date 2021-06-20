#include "Player.h"
#include "Table.h"
#include <iostream>
using namespace std;

table::table()
{

}
table::~table()
{

}

void table::showCardDeck()                                                // initiates show deck
{
	aDeck.showDeck();
}

void table::playBlackJack()                                               // initiates gameplay. 
{
	int playBlackJack;
	do
	{
		aDeck.showDeck();
		aDeck.shuffleDeck();
		cout << "Dealing....." << endl << endl;
		dealBlackJack();
		cout << endl; cout << endl;
		cout << "Welcome To The World Of Blackjack" << endl;
		cout << "-----Game start----->" << endl;
		cout << endl;
		showPlayerHands();cout << endl;
		cout << "------------> Hit ......." << endl << endl;
		hitHand();cout << endl;
		cout << "------------> Cards ......." << endl << endl;
		showPlayerHands();cout << endl;
		cout << "------------> Result ......." << endl << endl;
		getWinners();

		cout << "Press 0 to quit or 1 to play another hand: ";            // allows player to quit or play again
		cin >> playBlackJack;
		cout << endl;
		while (playBlackJack != 0 && playBlackJack != 1)
		{
			cout << "Enter number dosen't exist. Please re-enter:";
			cin >> playBlackJack;
			cout << endl;
		}
		if (playBlackJack == 0) { break; }
	} 	while (playBlackJack == 1);
}

void table::dealBlackJack()                                               // deals cards to players, moves through four players and dealer, initially giving two cards each
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			thePlayers[i].getCard(aDeck.dealCard());
		}
	}
	for (int k = 0; k < 2; k++)
	{
		aDealer.getCard(aDeck.dealCard());
	}
}
void table::showPlayerHands()                                             // shows what players have in hand
{
	for (int i = 0; i < 4; i++)
	{
		cout << "Player " << i + 1 << " : " << endl;
		thePlayers[i].showYourHand();
		cout << endl;
	}
	cout << "Dealer : " << endl;
	aDealer.showYourHand();
}

void table::hitHand()                                                      // lines 80 - 145  players and dealer > hit or hold , dealer must hit if less that 17
{
	int hitHand;

	for (int i = 0; i < 4; i++)
	{   // Player
		cout << "Player " << i + 1 << " has: " << thePlayers[i].getScore() << endl << "Do you want to hit? Press 1 for yes, 0 for no: ";
		cin >> hitHand;
		cout << endl;
		while (hitHand)
		{
			if (hitHand != 0 && hitHand != 1)
			{
				cout << "Enter number dosen't exist. Please re-enter:";
				cin >> hitHand;
				cout << endl;
			}
			if (hitHand == 0) { break; }
			if (hitHand == 1)
			{
				if (thePlayers[i].getScore() >= 21) { break; }

				thePlayers[i].getCard(aDeck.dealCard());
				cout << "Player " << i + 1 << " has: " << thePlayers[i].getScore() << endl;

				if (thePlayers[i].getScore() >= 21)
				{
					cout << endl;
					break;
				}
				cout << "Do you want to hit? Press 1 for yes, 0 for no: ";
				cin >> hitHand;
				cout << endl;
			}
		}
	}
	// Dealer
	cout << "Dealer " << " has: " << aDealer.getScore() << endl << "Do you want to hit? Press 1 for yes, 0 for no: ";
	cin >> hitHand;
	cout << endl;
	while ((aDealer.canHit()) && (hitHand))
	{
		if (hitHand != 0 && hitHand != 1)
		{
			cout << "Enter number dosen't exist. Please re-enter:";
			cin >> hitHand;
			cout << endl;
		}
		if (hitHand == 0) { break; }
		if (hitHand == 1) 
		{
			if (aDealer.getScore() >= 21) { break; }

			aDealer.getCard(aDeck.dealCard());
			cout << "Dealer " << " has: " << aDealer.getScore() << endl;
			if (aDealer.getScore() >= 21)
			{
				cout << endl;
				break;
			}
			cout << "Do you want to hit? Press 1 for yes, 0 for no: ";
			cin >> hitHand;
			cout << endl;
		}
	}
}

void table::getWinners()                                                   // lines 147 - 184 determine winners/losers
{
	int dealerScore = aDealer.getScore();
	int playerScore = 0;

	for (int i = 0; i < 4; i++)
	{
		playerScore = thePlayers[i].getScore();
		if ((playerScore > dealerScore) && (playerScore < 22))
		{
			if (playerScore == 21) 
			{
				cout << "Blackjack!";
			}
			cout << "Player " << i + 1 << " WINNER!" << endl;
		}
		else if ((playerScore < dealerScore) && (dealerScore < 22))
		{
			cout << "Player " << i + 1 << " loses." << endl;
		}
		else if (playerScore > 21)
		{
			cout << "Player " << i + 1 << " Bust! You lose." << endl;
		}
		else if ((dealerScore > 21) && (playerScore < 22))
		{
			cout << "Dealer Bust!" << "Player " << i + 1 << " WINNER!" << endl;
		}
		else if (dealerScore == playerScore) 
		{
			cout << "This game ended in a tie!";
			if ((dealerScore == 21) && (playerScore == 21))
			{
				cout << "Blackjack" << endl;
			}
		}
	}
}