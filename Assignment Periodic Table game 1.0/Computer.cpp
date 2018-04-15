#include "stdafx.h"
#include "Computer.h"
#include <list>
#include <string>
#include <iostream>

Computer::Computer(std::list<std::string> &words, std::string &lastAnswer, std::string diffLevel) : words(words), lastAnswer(lastAnswer), diffLevel(diffLevel)
{

}


Computer::~Computer()
{
}


std::string Computer::getAnswer()
{
	//holds the letter m
	char m = 'm';
	//AI answer if there is a option to use a word that ends in m
	std::string AIanswer;
	//Answer that gets sent to the periodic.cpp main as the Computers answer
	std::string ComputerAnswer;
	std::cout << diffLevel << std::endl;
	//where Last letter of the last played answer will be held
	char lastLetter;

	//for loop to itterate through the list
	for (auto& i : words) {
		//gets the last letter of the last anser played
		lastLetter = lastAnswer[lastAnswer.length() - 1];
		//changes the casing of the last letter to uppercase
		lastLetter = toupper(lastLetter);

		//-----------------------------------------------------------------------------------------
//easy difficulty
		if ((diffLevel == "3") || (diffLevel == "2") || (diffLevel == "1")) {
			if (lastLetter == i[0]) {
				return i;
				std::cout << ComputerAnswer << std::endl;
				std::cout << "easy" << std::endl;
			}
		}
		//----------------------------------------------------------------------------------------

//Medium difficulty
				//check to see if the last letter is = to the first letter of the list word being checked.
		if (diffLevel == "2" || (diffLevel == "3")) {
			//sets the Computers answer if there is an option to avoid setting on m
			if ((lastLetter == i[0]) && (i.length() - 1 != m)) {
				return i;
				std::cout << ComputerAnswer << std::endl;
				std::cout << "Medium" << std::endl;
			}
		}
		//----------------------------------------------------------------------------------------
//Hard difficulty
	//If lastLetter = Mit will ensure AI victory
		if (diffLevel == "3") {
			//sets the Computers answer to a word that both starts and ends with the letter M
			if ((lastLetter == i[0]) && (i[i.length() - 1] == m)) {
				return i;
				std::cout << "hard" << std::endl;
			}
		}
		std::cout << diffLevel << std::endl;
		ComputerAnswer = i;
		return ComputerAnswer;
	}
}