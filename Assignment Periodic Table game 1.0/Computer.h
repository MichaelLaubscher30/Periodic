#pragma once
#include <string>
#include "Player.h"
#include <list>
class Computer:public Player
{
private:
	std::list<std::string>& words;
public:
	Computer(std::list<std::string>&words);
	~Computer();
	std::string getAnswer()override;
	

};

