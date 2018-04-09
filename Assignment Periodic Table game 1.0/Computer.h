#pragma once
#include <string>
#include "Player.h"
#include <list>
class Computer:public Player
{
private:
	std::list<std::string>& words;
	std::string &lastAnswer;
public:
	Computer(std::list<std::string>&words,std::string &lastAnswer);
	~Computer();
	std::string getAnswer()override;



};

