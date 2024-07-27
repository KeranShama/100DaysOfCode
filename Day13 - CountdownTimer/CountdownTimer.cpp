#include <chrono>
#include <thread>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h> // For _kbhit() and _getch()

#pragma comment(lib, "winmm.lib")

using namespace std;

void ShowTimer() {
    cout << "----------------------------------------------" << endl;
    cout << "---               ----------------------------" << endl;
    cout << "-                |  " << endl;
    cout << "-    OUTPUT      |  00 : 00 : 00 " << endl;
    cout << "-                |  " << endl;
    cout << "---               ----------------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-    PAUSE      |     RESUME    |    EXIT    -" << endl;
    cout << "-      p        |       r       |      e     -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;

}

void DisplayTimer(int h, int m, int s) {
    cout << "----------------------------------------------" << endl;
    cout << "---               ----------------------------" << endl;
    cout << "-                |  " << endl;
    cout << "-    OUTPUT      |  " << h << " : " << m << " : " << s << endl;
    cout << "-                |  " << endl;
    cout << "---               ----------------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-    PAUSE      |     RESUME    |    EXIT    -" << endl;
    cout << "-      p        |       r       |      e     -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;

}

int main(){

    while (true) {
        char c;
        bool correct = true;

        int s, m, h;
        bool paused = false;

        system("cls");
        ShowTimer();

        cout <<"Enter hours : ";
        cin >> h;
        if (h < 0 || h>24) {
            cout << "Entered hours value is invalid" << endl;
            correct = false;
        }
        cout << "Enter minutes : ";
        cin >> m;
        if (m < 0 || m >= 60) {
            cout << "Entered minutes value is invalid" << endl;
            correct = false;
        }
        cout << "Enter seconds : ";
        cin >> s;
        if (s < 0 || s >= 60) {
            cout << "Entered seconds value is invalid" << endl;
            correct = false;
        }

        if (s == 0 && m == 0 && h == 0)
        {
            cout << "You need to enter a valid time" << endl;
            correct = false;
        }

        if (correct) {
            while ((h > 0 || m > 0 || s > 0))
            {

                if (!paused) {

                    system("cls");
                    DisplayTimer(h, m, s);

                    this_thread::sleep_for(chrono::seconds(1));
                    if (s == 0 && m == 0)
                    {
                        h--;
                        m = 59;
                        s = 59;
                    }
                    else if (s == 0)
                    {
                        m--;
                        s = 59;
                    }
                    else {
                        s--;
                    }
                }
                if (_kbhit()) {
                    char ch = _getch();
                    if (ch == 'p' || ch == 'P') {
                        paused = true;
                    }
                    else if (ch == 'r' || ch == 'R') {
                        paused = false;
                    }
                    else if (ch == 'e' || ch == 'E') {
                        cout << endl << "Key 'E' pressed." << endl;
                        return 1;
                    }

                    if (paused) {
                        cout << "Paused. Press 'R' to resume." << endl;
                    }
                }
            }

            cout << "Time is up! Music is playing!" << endl;
            PlaySound(TEXT("alarm.wav"), NULL, SND_FILENAME | SND_SYNC);

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