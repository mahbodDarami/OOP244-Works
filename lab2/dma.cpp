// Name: [Mahbod Darami]
// Email: [mdarami@myseneca.ca]
// Student ID: [117135244]
// Date: [2025-01-18]


/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "dma.h"
using namespace std;
namespace seneca {
	/// <summary>
   /// Receives an unknown number 
   /// of double numbers from the console and prints them in reverse order.
   /// </summary>
	
	void reverse() {
		int size;
		cout << "Enter the number of double values:" << endl;
		cout << "> ";
		cin >> size;
		double* numbers = nullptr;
		numbers = new double[size];
		for (int i = 0; i < size; i++) {
			cout << i + 1 << "> ";
			cin >> numbers[i];
		}
		for (int i = 0; i < size / 2; i++) {
			double temp = numbers[i];
			numbers[i] = numbers[size - i - 1];
			numbers[size - i - 1] = temp;
		}
		for (int i{}; i < size; i++) {
			cout << numbers[i] << endl;
		}
		delete[] numbers;
		numbers = nullptr;



	}
	/*struct Contact {
		char
			m_name[21],
			m_lastname[31];
		long long
			m_phoneNumber;
	};*/
	Contact* getContact() {
		Contact* contactptr = nullptr;
		contactptr = new Contact;
		cout << "Name: ";
		cin >> contactptr->m_name;
		cout << "Last name: ";
		cin >> contactptr->m_lastname;
		cout << "Phone number: ";
		cin >> contactptr->m_phoneNumber;
		return contactptr;
	}
	/*2 - display

		Receives a constant Contact reference and prints the contents as follows :

	Name Lastname, +Phonenumber
		and goes to newline*/
	void display(const Contact& cptr ) {
		cout << cptr.m_name << " "<<  cptr.m_lastname << ", +" << cptr.m_phoneNumber << endl;

	}
	void deallocate(Contact* cptr) {
		delete cptr;
		cptr = nullptr;
	}
	/*Receives a Contact reference and returns nothing Empties the
		Contact reference member variables to set the names to empty C - strings and the phone number to zero.*/
	void setEmpty(Contact& cptr) {
		cptr.m_lastname[0] = '\0';

		cptr.m_name[0]= '\0';
		cptr.m_phoneNumber = 0;


	}

		

}
