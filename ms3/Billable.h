/***********************************************************************
// OOP244 Project, milestone 3:
//
// File	Billable.h
// Version 1.0
// Student Name and ID: Mahbod Darami - 117135244
// Date 2025-03-24
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

#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H

#include "Utils.h"
#include "constants.h"
#include <iostream>
#include <fstream>

namespace seneca {
	class Billable {
		char* m_name = nullptr;
		double m_price = 0.0;
	protected:
		void setPrice(double value);
		void name(const char* name);
	public:
		Billable();
		Billable(const Billable& other);
		Billable& operator=(const Billable& other);
		virtual ~Billable();
		virtual double price()const;
		virtual std::ostream& print(std::ostream& ostr = std::cout)const = 0;
		virtual bool order() = 0;
		virtual bool ordered()const = 0;
		virtual std::ifstream& read(std::ifstream& file) = 0;
		operator const char* ()const;

	};
	double operator+(double money, const Billable& B);
	double& operator+=(double& money, const Billable& B);
}
#endif
