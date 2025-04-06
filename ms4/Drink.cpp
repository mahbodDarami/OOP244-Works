//Student Name and ID: Mahbod Darami - 117135244
// Date 2025-03-24
// Author Mahbod Darami
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#include "Drink.h"
#include "Utils.h"
#include "Menu.h"
#include <iomanip>
using namespace std;
namespace seneca {
	Drink::Drink() :m_size('\0') {}
	bool Drink::ordered()const {
		return m_size == 'S' || m_size == 'M' ||
			m_size == 'L' || m_size == 'X';
	}
	std::ifstream& Drink::read(std::ifstream& file) {
		if (file) {
			char temp[1024] = {};
			double p;
			file.getline(temp, 1024, ',');
			file >> p;
			file.ignore(1000, '\n');
			if (file) {
				name(temp);
				setPrice(p);
				m_size = '\0';

			}
		}
		return file;
	}
	bool Drink::order() {
			Menu m("Drink Size Selection", "Back", 3);
			m << "Small" << "Medium" << "Larg" << "Extra Large";
			size_t choice = m.select();

			if (choice == 1) {
				m_size = 'S';
			}
			else if (choice == 2) {
				m_size = 'M';
			}
			else if (choice == 3) {
				m_size = 'L';
			}
			else if (choice == 4) {
				m_size = 'X';
			}
			else {
				m_size = '\0';
			}

			return ordered();
		}
	std::ostream& Drink::print(std::ostream& ostr) const {
		ostr.setf(std::ios::left);
		ostr.width(28);
		ostr.fill('.');
		ostr << (const char*)(*this);
		ostr.fill(' '); 
		const char* sizeCode = ".....";
		if (ordered()) {
			const char* sizes[] = { ".....", "SML..", "MID..", "LRG..", "XLR.." };
			size_t index = (m_size == 'S') ? 1 :
				(m_size == 'M') ? 2 :
				(m_size == 'L') ? 3 : 4;
			sizeCode = sizes[index];
		}
		ostr << sizeCode;
		ostr.setf(std::ios::fixed | std::ios::right);
		ostr.precision(2);
		ostr.width(7);
		ostr << price();

		ostr.unsetf(std::ios::left | std::ios::right);
		return ostr;
	}	double Drink::price() const {
		double base = Billable::price();
		if (!ordered()) return base;

		switch (m_size) {
		case 'S': return base * 0.5;   
		case 'M': return base * 0.75;   
		case 'L': return base;          
		case 'X': return base * 1.5;    
		default:  return base;
		}
	}


}

