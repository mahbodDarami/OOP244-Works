/***********************************************************************
// OOP244 Project, milestone 2: tester program
//
// File	Menu.cpp
// Version 2.0
// Student Name and ID: Mahbod Darami - 117135244
// Date 2025-03-15
// Author Fardad
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include <iostream>
#include "Billable.h"
namespace seneca {
	Billable::Billable() {};

	
	Billable::Billable(const Billable& other) {
		ut.alocpy(m_name, other.m_name);
	}
	Billable& Billable::operator=(const Billable& other) {
		if (this != &other) {
			ut.alocpy(m_name, other.m_name);  
			m_price = other.m_price;
		}
		return *this;
	}
	void Billable::price(double value) {
		this->m_price = value;
	}
	void Billable::name(const char* name) {
		ut.alocpy(m_name, name);
		}
	 Billable::~Billable() {
		delete[] m_name;
	}
	 double Billable::price()const {
		 return m_price;
	 }
	 Billable::operator const char* ()const {
		 return m_name;
	 }
	 double operator+(double money, const Billable& B) {
		 return money + B.price();
	 }
	 double& operator+=(double& money, const Billable& B) {
		 return money += B.price();
	 }
}