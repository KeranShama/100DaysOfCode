#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void ShowUI() { 
    cout << "----------------------------------------------" << endl;
    cout << "---                                        ---" << endl;
    cout << "-                                            -" << endl;
    cout << "-          ROCK PAPER SCISSORS GAME          -" << endl;
    cout << "-                                            -" << endl;
    cout << "---                                        ---" << endl;
    cout << "==============================================" << endl;
    cout << "-                                            -" << endl;
    cout << "-      Enter your choice :                   -" << endl;
    cout << "-                                            -" << endl;
    cout << "==============================================" << endl;
    cout << "-       ROCK   |   PAPER   |   SCISSORS      -" << endl;
    cout << "-         1    |     2     |      3          -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-        EXIT         |       CONTINUE       -" << endl;
    cout << "-          e          |           c          -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
}

void DisplayUI(string ch, string ra, string res, int suser, int scom, int count) { 
    cout << "----------------------------------------------" << endl;
    cout << "---                                        ---" << endl;
    cout << "-                                            -" << endl;
    cout << "-          ROCK PAPER SCISSORS GAME          -" << endl;
    cout << "-                                            -" << endl;
    cout << "---                                        ---" << endl;
    cout << "==============================================" << endl<<endl;
    
    if(res == "Invalid"){
        cout << "   Invalid Input. Please Try Again!" << endl << endl;
    }
    else{
        cout << "   Your choice : "<< ch << endl;         
        cout << "   My choice : "<< ra << endl;
        cout << "   Result : "<< res << endl<<endl;  
    }
	
	cout << "----------------------------------------------" << endl <<endl;
	
    cout << "   Score - You: " << suser << " | Computer: " << scom << " | Tries: " << count << endl << endl;
    cout << "==============================================" << endl;
    cout << "-       ROCK   |   PAPER   |   SCISSORS      -" << endl;
    cout << "-         1    |     2     |      3          -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-        EXIT         |       CONTINUE       -" << endl;
    cout << "-          e          |           c          -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
}

int main(){
	
	int suser = 0, scom = 0, count = 0;
    srand(time(0));

    while(true){
        int choice,random;
        int res;
        char c;
		string ch="", ra="", result="";

        system("cls");
        ShowUI();

        cout<<"\n\nEnter your choice : ";
        cin>>choice;
        
        random = 1 + rand() % 3;

        if(choice > 3 || choice < 1){
            ch = "";
            ra = "";
            result = "Invalid";
        }
        else{

            if(choice == 1 && random == 3){
                res = 1;
				suser++;
            }
            else if(choice == 3 && random == 2){
                res = 1;
				suser++;
            }
            else if(choice == 2 && random == 1){
                res = 1;
				suser++;
            }
            else if(choice == 3 && random == 1){
                res = 0;
				scom++;
            }
            else if(choice == 2 && random == 3){
                res = 0;
				scom++;
            }
            else if(choice == 1 && random == 2){
                res = 0;
				scom++;
            }
            else{
                res = -1;
            }

            ch = (choice == 1) ? "Rock" : ((choice == 2) ? "Paper" : "Scissors" );
            ra = (random == 1) ? "Rock" : ((random == 2) ? "Paper" : "Scissors" );
            result = (res == 1) ? "You are the winner!" : ((res == 0) ? "You Lost it!" : "It's a tie!" );

        }
        count++;
        system("cls");
        DisplayUI(ch, ra, result,suser, scom, count);
        
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

