#include "stdafx.h"
#include "Computer.h"
#include <list>
#include <string>
#include <iostream>

Computer::Computer(std::list<std::string> &words,std::string &lastAnswer) : words(words),lastAnswer(lastAnswer)
{

}


Computer::~Computer()
{
}

std::string Computer::getAnswer()
{

	std::string ComputerAnswer;
	char lastLetter;
	for (auto& i : words) {
		lastLetter = lastAnswer[lastAnswer.length() - 1];
			if (lastLetter == i[0]) {
			ComputerAnswer = i;
		}
	}
	return 	ComputerAnswer;
}
