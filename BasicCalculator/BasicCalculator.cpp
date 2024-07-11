#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>

using namespace std;

void showCalculator(){
    cout << "----------------------------------------------" << endl;
    cout << "---                                        ---" << endl;
    cout << "-                                            -" << endl;
    cout << "-                 CALCULATOR                 -" << endl;
    cout << "-                                            -" << endl;
    cout << "---                                        ---" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-      +       |      -        |       *     -" << endl;
    cout << "-     Add      |     Sub       |      Mul    -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-     /        |      %        |       ^     -" << endl;
    cout << "-    Div       |     Mod       |     Power   -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-     s        |      r        |       l     -" << endl;
    cout << "-   Square     |    SqRoot     |      Log    -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-     q        |      c        |       e     -" << endl;
    cout << "-    Cube      |     CLR       |     EXIT    -" << endl;
    cout << "----------------------------------------------" << endl;
}

void displayCalculator(double ans, const string& str){
    cout << "----------------------------------------------" << endl;
    cout << "---                    -----------------------" << endl;
    cout << "-                     |  " << str << endl;
    cout << "-    OUTPUT           |  " << ans << endl;
    cout << "-                     |                       " << endl;
    cout << "---                    -----------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-      +       |      -        |       *     -" << endl;
    cout << "-     Add      |     Sub       |      Mul    -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-     /        |      %        |       ^     -" << endl;
    cout << "-    Div       |     Mod       |     Power   -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-     s        |      r        |       l     -" << endl;
    cout << "-   Square     |    SqRoot     |      Log    -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-     q        |      c        |       e     -" << endl;
    cout << "-    Cube      |     CLR       |     EXIT    -" << endl;
    cout << "----------------------------------------------" << endl;
}

int main(){
    double num1 = 0.0, num2 = 0.0, res = 0.0;
    char ex = ' ';
    char str[50];
    bool isRes = false;

    showCalculator();

    while(ex != 'e' && ex != 'E'){
        cout << "Enter the operator value : ";
        cin >> ex;

        sprintf(str, "%.2f", res);

        if((ex == '+' || ex == '-' || ex == '*' || ex == '/' || ex == '%' || ex == '^') && !isRes){
            cout << "Enter number 1 : ";
            cin >> num1;
            cout << "Enter number 2 : ";
            cin >> num2;
        } else if((ex == '+' || ex == '-' || ex == '*' || ex == '/' || ex == '%' || ex == '^') && isRes){
            cout << "Enter number : ";
            cin >> num2;
        } else if(ex == 'e' || ex == 'E' || ex == 'c' || ex == 'C'){
            // Do nothing, handled in switch
        } else {
            if(res == 0){
                cout << "Enter number : ";
                cin >> num1;
            }
        }

        switch(ex){
            case '+':
                res = num1 + num2;
                sprintf(str, "%.2f + %.2f", num1, num2);
                break;
            case '-':
                res = num1 - num2;
                sprintf(str, "%.2f - %.2f", num1, num2);
                break;
            case '*':
                res = num1 * num2;
                sprintf(str, "%.2f * %.2f", num1, num2);
                break;
            case '/':
                if(num2 == 0){
                    cout << "Division by zero error\n";
                    res = 0;
                    continue;
                }
                res = num1 / num2;
                sprintf(str, "%.2f / %.2f", num1, num2);
                break;
            case '%':
                if(static_cast<int>(num2) == 0){
                    cout << "Division by zero error\n";
                    res = 0;
                    continue;
                }
                res = static_cast<int>(num1) % static_cast<int>(num2);
                sprintf(str, "%.2f %% %.2f", num1, num2);
                break;
            case '^':
                res = pow(num1, num2);
                sprintf(str, "%.2f ^ %.2f", num1, num2);
                break;
            case 's':
            case 'S':
                res = num1 * num1;
                sprintf(str, "s%.2f", num1);
                break;
            case 'r':
            case 'R':
                if(num1 < 0){
                    cout << "Square root of negative number error\n";
                    res = 0;
                    continue;
                }
                res = sqrt(num1);
                sprintf(str, "r%.2f", num1);
                break;
            case 'l':
            case 'L':
                if(num1 <= 0){
                    cout << "Logarithm of non-positive number error\n";
                    res = 0;
                    continue;
                }
                res = log(num1);
                sprintf(str, "l%.2f", num1);
                break;
            case 'q':
            case 'Q':
                res = num1 * num1 * num1;
                sprintf(str, "q%.2f", num1);
                break;
            case 'e':
            case 'E':
                break;
            case 'c':
            case 'C':
                str[0] = '\0';
                res = 0;
                break;
            default:
                cout << "Invalid Expression";
        }

        system("cls"); // Clear the screen
        displayCalculator(res, str);
        isRes = true;

        num1 = res;
        if(ex == 'c' || ex == 'C'){
            system("cls");
            showCalculator();
            res = 0;
            isRes = false;
        }
    }

    return 0;
}

