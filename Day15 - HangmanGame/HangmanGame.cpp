#include <iostream>
#include <vector>
#include <cctype>   // for tolower()
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

void ShowUI(vector<char> wordCopy, int i, int r) {
	cout << "----------------------------------------------" << endl;
	cout << "---                                        ---" << endl;
	cout << "-                                            -" << endl;
	cout << "-               HANGMAN GAME                 -" << endl;
	cout << "-                                            -" << endl;
	cout << "---                                        ---" << endl;
	cout << "==============================================" << endl << endl;
	cout << "          ";
	for (char c : wordCopy) {
		cout << c;
	}
	cout << endl << endl;
	cout << "==============================================" << endl;
	cout << "-   Incorrect Guesses |  Remaining Guesses   -" << endl;
	cout << "-            " << i << "        |           " << r << "          -" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "-        EXIT         |       CONTINUE       -" << endl;
	cout << "-          e          |           c          -" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;
}

void DisplayUI(string word, int i, int r) {
	cout << "----------------------------------------------" << endl;
	cout << "---                                        ---" << endl;
	cout << "-                                            -" << endl;
	cout << "-               HANGMAN GAME                 -" << endl;
	cout << "-                                            -" << endl;
	cout << "---                                        ---" << endl;
	cout << "==============================================" << endl <<endl;
	cout << "          "<<word;
	cout << endl << endl;
	cout << "==============================================" << endl;
	cout << "-   Incorrect Guesses |  Remaining Guesses   -" << endl;
	cout << "-            " << i << "        |           " << r << "          -" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "-        EXIT         |       CONTINUE       -" << endl;
	cout << "-          e          |           c          -" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;
}

int main() {

	while (true) {

		vector<string> wordList = { "apple", "banana", "cherry", "grape", "orange", "mango" };
		srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
		string word = wordList[rand() % wordList.size()];

		vector<char> wordCopy(word.length());
		char ch, c;
		int maxGuess = 6, incorrect = 0;
		bool isLetter = false, isAll = false;


		for (char& c : wordCopy) {
			c = '#';
		}

		for (int i = 1; i <= maxGuess; i++) {
			system("cls");
			ShowUI(wordCopy, incorrect, maxGuess - i + 1);

			cout << endl;
			cout << "Enter one character : ";
			cin >> ch;
			ch = tolower(ch);

			for (int j = 0; j < word.length(); j++) {
				if (word[j] == ch) {
					isLetter = true;
					wordCopy[j] = ch;
				}
			}
			if (isLetter) {
				cout << "Correct Guess" << endl;
			}
			else {
				cout << "Wrong Guess" << endl;
				incorrect++;
			}

			isAll = true;
			for (int j = 0; j < word.length(); j++) {
				if (word[j] != wordCopy[j]) {
					isAll = false;
					break;
				}
			}
			if (isAll) {
				system("cls");
				DisplayUI(word, incorrect, 0);
				cout << "You won!" << endl;
				break;
			}
			isLetter = false;
		}

		if (!isAll) {
			system("cls");
			DisplayUI(word, incorrect, 0);
			cout << endl << "You Lost!" << endl;
			cout << "Correct word is " << word << endl;
		}
		
		cout << "\nExit/Continue (e/c) : ";
		cin >> c;

		if (c == 'e' || c == 'E') {
			break;
		}
		if (c != 'c' && c != 'C') {
			cout << "Invalid input" << endl;
			break;
		}
	}
	
	return 0;
}