#include "stdafx.h"
#include "Computer.h"
#include <list>
#include <string>
#include <iostream>

Computer::Computer(std::list<std::string> &words, std::string &lastAnswer) : words(words), lastAnswer(lastAnswer)
{

}


Computer::~Computer()
{
}


std::string Computer::getAnswer()
{
	extern int DiffLevel;

	int easy = 1;
	int medium = 2;
	int hard = 3;
	//holds the letter m
	char m = 'm';
	//AI answer if there is a option to use a word that ends in m
	std::string AIanswer;
	//Answer that gets sent to the periodic.cpp main as the Computers answer
	std::string ComputerAnswer;


	std::cout << DiffLevel << std::endl;
	//where Last letter of the last played answer will be held
	char lastLetter;
	//for loop to itterate through the list
	for (auto& i : words) {
		//gets the last letter of the last anser played
		lastLetter = lastAnswer[lastAnswer.length() - 1];
		//changes the casing of the last letter to uppercase
		lastLetter = toupper(lastLetter);


		//----------------------------------------------------------------------------------------
		//Easy difficulty
		switch (DiffLevel) {
		case 1:
			if (lastLetter == i[0]) {
				//sets the Computers answer to the first avaliable answer that fits the criteria
				ComputerAnswer = i;
				std::cout << ComputerAnswer << std::endl;
				std::cout << "easy" << std::endl;
			}
			return ComputerAnswer;
			words.remove(ComputerAnswer);
			break;




			//-----------------------------------------------------------------------------------------
			//Medium difficulty
		case 2:
			//check to see if the last letter is = to the first letter of the list word being checked.
			if ((lastLetter == i[0]) && (lastLetter != m)) {
				//sets the Computers answer if there is an option to avoid setting on m
				if ((i.length() - 1 != m)) {
					ComputerAnswer = i;
					std::cout << ComputerAnswer << std::endl;
					std::cout << "Medium" << std::endl;
					return ComputerAnswer;
					words.remove(ComputerAnswer);
					break;
				}

				 


				//-----------------------------------------------------------------------------------------
				//hard difficulty
		case 3:
			//If lastLetter = Mit will ensure AI victory
			if ((lastLetter == i[0]) && (lastLetter == m)) {
				//sets the Computers answer to a word that both starts and ends with the letter M
				if (i[i.length() - 1] == m) {
					ComputerAnswer = i;
					std::cout << "hard" << std::endl;

					return ComputerAnswer;
					words.remove(ComputerAnswer);
					break;
				}
			}
			}
		}
	}
}