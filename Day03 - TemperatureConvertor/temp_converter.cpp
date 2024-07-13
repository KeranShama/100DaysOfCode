#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>

using namespace std;

void showConverter(){
	cout << "----------------------------------------------" << endl;
    cout << "---                                        ---" << endl;
    cout << "-                                            -" << endl;
    cout << "-           TEMPERATURE CONVERTOR            -" << endl;
    cout << "-                                            -" << endl;
    cout << "---                                        ---" << endl;
    cout << "----------------------------------------------" << endl;
   	cout << "-     1        |       2       |      3      -" << endl;
    cout << "-   C -> F     |     F -> C    |    C -> K   -" << endl;
    cout << "----------------------------------------------" << endl;
	cout << "-     4        |       5       |      6      -" << endl;
    cout << "-   K -> C     |     K -> F    |    F -> K   -" << endl;
    cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;
    
}

void showConverter(char temp1, char temp2, double val1, double val2){
	cout << "----------------------------------------------" << endl;
    cout << "---                    -----------------------" << endl;
    cout << "-                     |  " << temp1 << " = " << val1 << endl;
    cout << "-    OUTPUT           |  " << endl;
    cout << "-                     |  " << temp2 << " = " << val2 << endl;
    cout << "---                    -----------------------" << endl;
    cout << "----------------------------------------------" << endl;
	cout << "-  TRY AGAIN   |    GO MENU    |     EXIT    -" << endl;
   	cout << "-     a        |       m       |      e      -" << endl;
    cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;	 
    
}


int main(){
	
	int n;
	double val1, val2;
	char c, temp1, temp2;
	
	while(true){
	
		system("cls");
		showConverter();
		
		cout<<"Enter number of desired convertion : ";
		cin>>n;
		
		while(true){
		
			cout<<"Enter value to be converted : ";
			cin>>val1;
		
				switch(n){
				case 1:
					temp1 = 'C';
					temp2 = 'F';
					val2 = (9/5.0)*val1 + 32;
					break;
				case 2:
					temp1 = 'F';
					temp2 = 'C';
					val2 = (5/9.0)*(val1-32);
					break;
				case 3:
					temp1 = 'C';
					temp2 = 'K';
					val2 = val1 + 273;
					break;
				case 4:
					temp1 = 'K';
					temp2 = 'C';
					val2 = val1 - 273;
					break;
				case 5:
					temp1 = 'K';
					temp2 = 'F';
					val2 = (9/5.0)*(val1 - 273) + 32;
					break;
				case 6:
					temp1 = 'F';
					temp2 = 'K';
					val2 = (5/9.0)*(val1-32) + 273;
					break;
				default:
					cout<<"Invalid Input"<<endl;
					return 0;
			}
			
			system("cls");
			showConverter(temp1, temp2, val1, val2);
			
			cout<<"Choose one option (a/m/e) : ";
			cin>>c;
			
			if(c == 'e' || c == 'E'){
				return 0;
			}
			else if(c == 'm' || c == 'M'){
				break;
			}
			else if(c == 'a' || c == 'A'){
				continue;
			}
			else{
				cout<<"Invalid Input"<<endl;
				return 0;
			}
		}	 
	}
	
	return 0;
}

