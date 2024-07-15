#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct candidate{ 
    string name;
    int votes;
};

void DisplayAtBeg(){
	cout << "----------------------------------------------" << endl;
    cout << "---                                        ---" << endl;
    cout << "-                                            -" << endl;
    cout << "-            SIMPLE VOTING SYSTEM            -" << endl;
    cout << "-                                            -" << endl;
    cout << "---                                        ---" << endl;
    cout << "----------------------------------------------" << endl<<endl;
	
	cout << "  .. OPTIONS .." << endl <<endl<<endl;
	
    cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;
}

void Display(vector<candidate> options){
	cout << "----------------------------------------------" << endl;
    cout << "---                                        ---" << endl;
    cout << "-                                            -" << endl;
    cout << "-            SIMPLE VOTING SYSTEM            -" << endl;
    cout << "-                                            -" << endl;
    cout << "---                                        ---" << endl;
    cout << "----------------------------------------------" << endl<<endl;
	
	cout << "   .. OPTIONS .." << endl <<endl;
	
   	for (int i = 0; i < options.size(); ++i){ 
        cout << "   "<<i + 1 << ". " << options[i].name << endl;
    }
	cout<<endl;
    cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;
}

void DisplayAtEnd(vector<candidate> options){
	cout << "----------------------------------------------" << endl;
    cout << "---                                        ---" << endl;
    cout << "-                                            -" << endl;
    cout << "-            SIMPLE VOTING SYSTEM            -" << endl;
    cout << "-                                            -" << endl;
    cout << "---                                        ---" << endl;
    cout << "----------------------------------------------" << endl<<endl;
	
	cout << "   .. VOTING RESULTS .." << endl <<endl;
	
   	for (int i = 0; i < options.size(); ++i){ 
        cout<<"   " << i+1 << ". " << options[i].name<<" - "<<options[i].votes<<" votes "<<endl;
    }
	cout<<endl;
    cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;
}

int main(){
	DisplayAtBeg();
	int num, cnum, vnum;
	
	cout<<"\nEnter the number of candidates : ";
	cin>>num;
	
	vector<candidate> vec(num);
	
	cout<<endl;
	for(int i=0; i<num; i++){
		cout<<"Enter candidate "<<i+1<<" : ";
		cin>>vec[i].name;
		vec[i].votes = 0;
	}
	
	system("cls");
	Display(vec);
	
	cout<<"\nEnter the number of voters : ";
	cin>>vnum;
	
	cout<<endl;	   
	for(int i=1; i<=vnum; i++){
		cout<<"The vote of user "<<i<<" : ";
		cin>>cnum;
		
		if(cnum<=num){
			vec[cnum-1].votes++;
		}
		else{
			cout<<"Invalid number. Try Again"<<endl;
			--i;
		}
	}
	
	system("cls");
	DisplayAtEnd(vec);
	
	return 0;
}

