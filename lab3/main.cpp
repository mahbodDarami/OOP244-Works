/***********************************************************************
// OOP244 Workshop 3 lab: tester program
//
// File	main.cpp
// Version 1.0
// Date	2024/09/11
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "CC.h"
using namespace std;
using namespace seneca;
int main() {

	char p_name;
	int age;
	char job;
    cout << "Enter your name: ";
    getline(cin, p_name); // Read full name (including spaces)

    cout << "Enter your job: ";
    getline(cin, job); // Read full job title

    cout << "Enter your age: ";
    cin >> age; // Read age

    cout << "Your name is " << p_name << ". Your job is " << job << " and your age is " << age << "." << endl;


	return 0;
}