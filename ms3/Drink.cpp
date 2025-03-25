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
				price(p);
				m_size = '\n';

			}
		}
		return file;
	}
	bool Drink::order() {
			Menu m("Drink Size Selection", "Back", 3);
			m << "Small" << "Medium" << "Large" << "Extra Large";
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
	ostream& Drink::print(ostream& ostr) const {
		ostr.setf(ios::left);
		ostr.width(28);
		ostr << (const char*)(*this);
		ostr.unsetf(ios::left);
		const char* sizeStr = ".....";
		const char* sizes[] = { ".....", "SML..", "MID..", "LRG..", "XLR.." };

		if (ordered()) {
			size_t index = (m_size == 'S') ? 1 : (m_size == 'M') ? 2 : (m_size == 'L') ? 3 : (m_size == 'X') ? 4 : 0;
			sizeStr = sizes[index];
		}
		ostr << sizeStr;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr.width(7);
		ostr << price();

		return ostr;
	}
	double Drink::price() const {
		double base = Billable::price();
		double multiplier = 1.0;

		if (ordered()) {
			multiplier = (m_size == 'S') ? 0.5 : (m_size == 'M') ? 0.75 : (m_size == 'L') ? 1.0 : (m_size == 'X') ? 1.5 : 1.0;
		}

		return base * multiplier;
	}


}

