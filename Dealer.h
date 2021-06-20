#pragma once
#include <iostream>
#include<string>
#include "Player.h"

class dealer : public player          // dealer class inherits everything from player class and adds boolean to determine if the dealer must hit or not
{
private:

public:								  // create public variables
	dealer();
	~dealer();

	bool canHit();
};