#include <iostream>
#include <string>
using namespace std;

string encryption(string text, int s){
    string result = "";

    for (int i=0; i<text.length(); i++){
        char c = text[i];
        if(isalpha(c)){
            char base = islower(c) ? 'a' : 'A';
            c = static_cast<char>((c - base + s) % 26 + base);
        }
        result += c;
    }
    
    return result;
}

string decryption(string str, int s){
    string res;
    res = encryption(str, 26-s);
    return res;
}

void ShowUI(){ 
    cout << "----------------------------------------------" << endl;
    cout << "---                                        ---" << endl;
    cout << "-                                            -" << endl;
    cout << "-          CAESAR CIPHER CALCULATOR          -" << endl;
    cout << "-                                            -" << endl;
    cout << "---                                        ---" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-                                            -" << endl;
    cout << "-   Enter text and shift number to process   -" << endl;
    cout << "-                                            -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-        EXIT         |       CONTINUE       -" << endl;
    cout << "-          e          |           c          -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
}

void DisplayUI(string result, char c, string text){ 
    cout << "----------------------------------------------" << endl;
    cout << "---                                        ---" << endl;
    cout << "-                                            -" << endl;
    cout << "-          CAESAR CIPHER CALCULATOR          -" << endl;
    cout << "-                                            -" << endl;
    cout << "---                                        ---" << endl;
    cout << "----------------------------------------------" << endl<<endl;
    
	if(c == 'e'){
		cout<<"Entered Text : "<<text<<endl;
		cout<<"Encrypted text : "<<result<<endl<<endl;
	}
	else if(c == 'd'){
		cout<<"Entered Text : "<<text<<endl;
		cout<<"Decryted text : "<<result<<endl<<endl;
	}
	else{
		cout<<"Invalid Option"<<endl<<endl;
	}
	
    cout << "----------------------------------------------" << endl;
    cout << "-        EXIT         |       CONTINUE       -" << endl;
    cout << "-          e          |           c          -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
}

int main(){
	
	string text, result;
    char c, ch;
    int shift;
		
	while(true){
		
		system("cls");
		ShowUI();
		
	    cout<<"Enter the text : ";
		cin.ignore();
	    getline(cin, text);
	    cout<<"Enter the shift number : ";
	    cin>>shift;
	    cout<<"Encryption/Decryption (e/d) : ";
	    cin>>c;
	
	    if(c == 'e' || c == 'E'){
	        result = encryption(text, shift);
			system("cls");
			DisplayUI(result,'e',text);
	    }
	    else if(c == 'd' || c == 'D'){
	        result = decryption(text, shift);
			system("cls");
			DisplayUI(result,'d',text);
	    }
	    else{
			system("cls");
	        DisplayUI("",'i',"");
	    }
		
		cout << "\nExit/Continue (e/c) : ";
        cin >> ch;

        if (ch == 'e' || ch == 'E') {
            break;
        }
        if (ch != 'c' && ch != 'C') {
            cout << "Invalid input" << endl;
            break;
        }
	}
    

    return 0;
}

