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
#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H
#include "Billable.h"
namespace seneca {
	class Drink :public Billable {
		char m_size;
	public:
		Drink();
		std::ostream& print(std::ostream& ostr
			= std::cout)const;
		bool order();
		bool ordered()const;
		std::ifstream& read(std::ifstream& file);
		double price()const;
	};
}
#endif