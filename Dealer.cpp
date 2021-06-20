#include "Dealer.h"

dealer::dealer()
{

}
dealer::~dealer()
{

}

bool dealer::canHit()										// sets up boolean to determine if the dealer can hit or not (must have at least 17 to not hit)
{
	bool canTakeCard = false;

	if ((getScore() < 17) && (getNumberOfCardsInHand() < 5))
	{
		canTakeCard = true;
	}
	return canTakeCard;
}