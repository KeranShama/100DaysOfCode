
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(char, bool, bool);

void ShowUI(char room, bool hasBook, bool hasKey) {
	cout << "----------------------------------------------" << endl;
	cout << "---                                        ---" << endl;
	cout << "-                                            -" << endl;
	cout << "-          TEXT-BASED ADVENTURE GAME         -" << endl;
	cout << "-                                            -" << endl;
	cout << "---                                        ---" << endl;
	cout << "==============================================" << endl;
	cout << "-                                            -" << endl;
	cout << "-      Enter your choice :                   -" << endl;
	cout << "-                                            -" << endl;
	cout << "==============================================" << endl;
	cout << "-    LIBRARY   |   KITCHEN   |   UPSTAIRS    -" << endl;
	cout << "-       l      |      k      |      u        -" << endl;
	cout << "----------------------------------------------" << endl;

	string current;
	if (room == 's') {
		current = "Start Room";
	}
	else if (room == 'k') {
		current = "Kitchen";
	}
	else if (room == 'l') {
		current = "Library";
	}
	else if (room == 'u') {
		current = "Upstairs";
	}
	else if (room == 'f') {
		current = "Final Room";
	}
	else if (room == 'w') {
		current = "Winning Room";
	}
	else {
		current = "Unknown Room";
	}
	cout << "      Room - "<< current << endl;

	if (hasKey) {
		if (hasBook) {
			cout << "      Key, Book                       " << endl;
		}
		else {
			cout << "      Key, No Book                       " << endl;
		}
	}
	else {
		if (hasBook) {
			cout << "      No Key, Book                       " << endl;
		}
		else {
			cout << "      No Key, No Book                       " << endl;
		}
	}
	
	cout << "----------------------------------------------" << endl;
	cout << "-        EXIT         |       CONTINUE       -" << endl;
	cout << "-          e          |           c          -" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;
}

int main() {

	while (true) {

		char c;
		char room = 's', inp;
		bool hasBook = false;
		bool hasKey = false;

		system("cls");
		ShowUI(room, hasBook, hasKey);

		while (room != 'w') {
			
			display(room, hasBook, hasKey);

			if (room == 's') {

				cout << endl << "Where do you want to go? (l/k/u): ";
				cin >> inp;
				inp = tolower(inp);

				if (inp == 'l') {
					room = 'l';
					system("cls");
					ShowUI(room, hasBook, hasKey);
				}
				else if (inp == 'k') {
					room = 'k';
					system("cls");
					ShowUI(room, hasBook, hasKey);
				}
				else if (inp == 'u') {
					room = 'u';
					system("cls");
					ShowUI(room, hasBook, hasKey);
				}
				else {
					cout << "Invalid choice. Try again." << endl;
				}

			}

			else if (room == 'l') {

				cout << endl << "Do you want to take the book? (y/n): ";
				cin >> inp;
				inp = tolower(inp);

				if (inp == 'y') {
					hasBook = true;
					room = 'k';
					system("cls");
					ShowUI(room, hasBook, hasKey);
					cout << "You find a hidden clue in the book. It says 'Go to the kitchen.'" << endl;
				}
				else if (inp == 'n') {
					room = 's';
					system("cls");
					ShowUI(room, hasBook, hasKey);
					cout << "You decide not to take the book and go back to the starting room." << endl;
				}
				else {
					cout << "Invalid choice. Try again." << endl;
				}

			}

			else if (room == 'k') {

				cout << endl << "Do you want to take the key? (y/n): ";
				cin >> inp;
				inp = tolower(inp);

				if (inp == 'y') {
					hasKey = true;
					room = 'f';
					system("cls");
					ShowUI(room, hasBook, hasKey);
					cout << "You use the key to unlock the final room." << endl;
				}
				else if (inp == 'n') {
					room = 's';
					system("cls");
					ShowUI(room, hasBook, hasKey);
					cout << "You decide not to take the key and go back to the starting room." << endl;
				}
				else {
					cout << "Invalid choice. Try again." << endl;
				}

			}

			else if (room == 'u') {

				if (hasBook) {

					cout << "You are in a room with a mysterious chest. The book you have contains a code to open it. You can now enter the code." << endl;
					string code;
					cout << endl << "Enter the code to open the chest: ";
					cin >> code;

					if (code == "1234") {
						room = 'f';
						system("cls");
						ShowUI(room, hasBook, hasKey);
						cout << "The chest opens to reveal a hidden map leading to the final room!" << endl;
					}
					else {
						room = 's';
						system("cls");
						ShowUI(room, hasBook, hasKey);
						cout << "Incorrect code. The chest remains locked." << endl;
					}

				}

				else {
					room = 's';
					system("cls");
					ShowUI(room, hasBook, hasKey);
					cout << "You find yourself in a locked room. Without the book, you can't proceed." << endl;
				}
			}

			else if (room == 'f') {
				if (hasKey) {
					room = 'w';
					system("cls");
					ShowUI(room, hasBook, hasKey);
					cout << "You use the key to unlock the final room. Congratulations, you have won the game!" << endl;

				}
				else {
					room = 'k';
					system("cls");
					ShowUI(room, hasBook, hasKey);
					cout << "You find yourself in the final room but realize you need the key to proceed." << endl;
				}
			}
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

void display(char room, bool hasBook, bool hasKey) {

	switch (room)
	{

	case 's': //Start
		cout << endl << "You are in a small, dimly lit room. There are two doors, one to the left and one to the right." << endl;
		break;

	case 'l': //Library
		cout << endl << "You are in a dusty library. There is a book on the table." << endl;
		if (hasBook) {
			cout << "You've already taken the book." << endl;
		}
		break;

	case 'k': //Kitchen
		cout << endl << "You are in a kitchen. There is a shiny key on the counter." << endl;
		
		if (hasKey) {
			cout << endl << "You've already taken the key." << endl;
		}
		break;

	case 'u': //Upstairs
		cout << endl << "You are upstairs in a room with a mysterious chest." << endl;
		break;

	case 'f': //Final room
		cout << endl << "You are in the final room, but you need the key to proceed." << endl;
		break;

	case 'w': //Winning room
		cout << endl << "Congratulations! You have found the treasure and won the game!" << endl;
		break;

	default:
		cout << endl << "Unknown Room";
		break;
	}
}


