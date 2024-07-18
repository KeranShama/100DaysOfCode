#include <iostream>
#include <string>
#include <vector>
using namespace std;

void ShowUI() {
    cout << "----------------------------------------------" << endl;
    cout << "---                                        ---" << endl;
    cout << "-                                            -" << endl;
    cout << "-            FIBONACCI CALCULATOR            -" << endl;
    cout << "-                                            -" << endl;
    cout << "---                                        ---" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-                                            -" << endl;
    cout << "-   Enter number(s) to calculate Fibonacci   -" << endl;
    cout << "-                                            -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-        EXIT         |       CONTINUE       -" << endl;
    cout << "-          e          |           c          -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
}

void DisplayUI(vector<string> results) {
    cout << "----------------------------------------------" << endl;
    cout << "---                                        ---" << endl;
    cout << "-                                            -" << endl;
    cout << "-            FIBONACCI CALCULATOR            -" << endl;
    cout << "-                                            -" << endl;
    cout << "---                                        ---" << endl;
    cout << "----------------------------------------------" << endl;

    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }

    cout << "----------------------------------------------" << endl;
    cout << "-        EXIT         |       CONTINUE       -" << endl;
    cout << "-          e          |           c          -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
}

void CalculateFibonacci(vector<int>& numbers, vector<string>& results) {
    for (size_t i = 0; i < numbers.size(); ++i) {
        int n = numbers[i];
        string result = "Fibonacci series upto " + to_string(n) + ": ";

        int prev = 0, curr = 1, next;

        if (n >= 0) {
            result += "0 ";
        }
        if (n >= 1) {
            result += "1 ";
        }

        if (n > 1) {
            while (true) {
                next = prev + curr;
                if (next > n) {
                    break;
                }
                result += to_string(next) + " ";
                prev = curr;
                curr = next;
            }
        }

        result += "\n";
        results.push_back(result);
    }
}


int main() {
    vector<int> numbers;
    char ch;
    vector<string> results;

    while (true) {
        numbers.clear();
        results.clear();

        system("cls");
        ShowUI();

        cout << "\nEnter number(s) separated by space (enter 0 to stop): ";

        int num;
        while (cin >> num && num != 0) {
            if (num <= 0) {
                cout << "Invalid number: " << num << endl;
                cout << "Calculation of this number is dismissed" << endl;
            } else {
                numbers.push_back(num);
            }
        }
        CalculateFibonacci(numbers, results);

        system("cls");
        DisplayUI(results);

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
