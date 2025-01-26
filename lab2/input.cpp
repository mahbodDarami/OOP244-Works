// Name: [Mahbod Darami]
// Email: [mdarami@myseneca.ca]
// Student ID: [117135244]
// Date: [2025-01-18]


/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "input.h"
using namespace std;
namespace seneca {
    int getInt() {
        int num = 0;
        bool done = false;
        do {
            // extract an integer from the console and put it in num
            cin >> num;
            // if this action fails (the integer is unreadable)
            if (cin.fail()) {
                cout << "Bad integer entry, please try again:\n> ";
                // clear the failure status to activate cin again
                cin.clear();
            }
            else {
                done = true;
            }
            // flush the keyboard buffer up to 1000 characters or '\n', whichever comes first
            cin.ignore(1000, '\n');
        } while (!done);
        return num;
    }
    int getInt(int minVal, int maxVal) {
        bool done = false;
        int num;
        do {
            num = getInt();
            if (num >= minVal && num <= maxVal) {
                done = true;
            }
            else {
                cout << "Invalid value, [" << minVal << "<ENTRY<" << maxVal << "]"<<endl;
                cout << "> ";
            }
        } while (!done);
        return num;
    }
    bool getInt(int& number, int minVal, int maxVal) {
         number = getInt();
         bool condition = false;
         if (number >= minVal && number <= maxVal) {
             condition = true;
         }
         return condition;

    }
}