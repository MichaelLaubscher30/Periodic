#include "stdafx.h"
#include "Player.h"
#include <iostream>



Player::Player():lives(3)
{
}


Player::~Player()
{
}

bool Player::IsAlive()
{
	return lives > 0;
}

void Player::DecreaseLives()
{
	lives--;
}

int Player::getLives()
{
	return lives;
}

std::string Player::getAnswer()
{
	std::string answer;
	getline(std::cin, answer);
	return answer;

}
