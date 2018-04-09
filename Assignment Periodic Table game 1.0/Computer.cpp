#include "stdafx.h"
#include "Computer.h"
#include <list>
#include <string>
#include <iostream>

Computer::Computer(std::list<std::string> &words) : words(words)
{

}


Computer::~Computer()
{
}

std::string Computer::getAnswer()
{
	std::string ComputerAnswer;
	for (auto i : words) {
		if (std::string lastAnswer) {

		}
	}
	return 	ComputerAnswer;
}
