//Michael Laubscher
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream> 



using namespace std;

/*
This function reads a file and stores each line in a list of strings*/
void readFile(list<string>& l, string Elements1) {
	std::ifstream ifs(Elements1);
	string v;
	while (getline(ifs, v)) {
		l.push_back(v);
	}
}

string toLowerCase(string moo) {
	string mooLower;
	for (int o = 0; o < moo.length(); o++) {
		mooLower += tolower(moo[o]);

	}
	return mooLower;
}

bool equalsIgnoreCase(string l, string s) {
	return toLowerCase(l) == toLowerCase(s);
}

/*
This function returns true if a specified string is contained in a list
*/
//function that cycles through the list and ignores the case
bool isin(list<string> l, string s) {
	for (auto i : l) {
		if (equalsIgnoreCase(i, s)) {
			cout << "Your word has been accepted" << endl;
			return true;
		}

	}
	cout << "Your word does not match the criteria" << endl;
	return false;
}
//Life check
void lives(int P1, int P2) {
	if (P1 == 0) {
		cout << "Player 2 Wins" << endl;

	}
	if (P2 == 0) {
		cout << "Player 1 Wins" << endl;
	}
}

/*
This function returns true if the last letter of one string matches the first letter of another
@return	true if first and last characters are equal, regardless of case
*/

//Checks to see if the two ansers are matching
bool match(string answer, string lastAnswer) {
	//    stops error at the start of the game where lastanser was empty
	if (lastAnswer.empty()) {
		return false;
	}
	//    specifies the location of the characters I want to focus on
	char f = answer[0];
	char end = lastAnswer[lastAnswer.length() - 1];
	//    converts them to lowercase
	if (tolower(f) == tolower(end)) {
		cout << "Next move" << endl;
		return true;
	}
	else {
		cout << "Your word does not fulfill the objective" << endl;

		return false;
	}
}
//Checks the answer given
bool answer(list<string> playerWords, string &lastAnswer) {
	string answer = "";
	getline(cin, lastAnswer);
	//    Checks to see if the word is found in the external file
	if (!isin(playerWords, lastAnswer)) {
		return false;
	}
	//    Checks to see if there is a match between the first and last letters
	if (!match(lastAnswer, answer)) {
		return false;
	}
	//    last Answer takes the value of answer
	lastAnswer = answer;

	return true;
}
//Life deduction
bool lives(bool success, int &playerLives) {
	if (!success) {
		playerLives--;
	}

	return playerLives > 0;
}

//insert program here....

int main() {

	list<string> playerWords;
	readFile(playerWords, "Elements1.txt");
	int player1Lives = 3;
	int player2Lives = 3;

	cout << "Welcome to the Periodic table game" << endl;
	cout << "Players will each take turns typing in names of the elements" << endl;
	cout << "on the periodic table" << endl;
	cout << "You will need to match the first letter of your word to the last" << endl;
	cout << "letter played by the other player" << endl;
	cout << "Good luck" << endl;





	cout << "Round START" << endl;

	bool player1Turn = true;

	string lastAnswer;

	while (true) {
		if (player1Turn) {
			cout << "player One please enter your word" << endl;
			bool success = answer(playerWords, lastAnswer);
			bool playerAlive = lives(success, player1Lives);
			if (player1Turn) {
				success == lastAnswer;
			}
			else {
				return player1Turn;
				break;
			}

			if (!playerAlive) {
				cout << "Player 2 Wins" << endl;
				break;
			}

			else {
				cout << "player Two please enter your word" << endl;
				bool success = answer(playerWords, lastAnswer);
				bool playerAlive = lives(success, player2Lives);
				if (!playerAlive) {
					cout << "Player 1 Wins" << endl;
					break;
				}

			}
		}

		player1Turn = !player1Turn;

	}
}






