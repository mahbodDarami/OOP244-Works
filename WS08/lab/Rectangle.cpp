#include "Rectangle.h"
#include "LblShape.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
//workshop 8
//written by Mahbod Darami - 117135244
//all codes written by me - 2025-03-25


namespace seneca {
    Rectangle::Rectangle() : m_width(0), m_height(0) {}

    Rectangle::Rectangle(const char* label, int width, int height) 
        : LblShape(label), m_width(width), m_height(height) {
        if (m_height < 3) m_height = 3;
        if (m_width < ut.strlen(label) + 2) {
            m_width = ut.strlen(label) + 2;
        }
    }

    void Rectangle::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.ignore(1000, '\n');
    }

	void Rectangle::draw(std::ostream& ostr) const {
		if (m_width > 0 && m_height > 0) {
			ostr << "+";
			for (int i = 0; i < m_width - 2; i++) {
				ostr << "-";
			}
			ostr << "+" << std::endl;
			ostr << "|";
			ostr.setf(std::ios::left);
			ostr.width(m_width - 2);
			ostr << label() << "|" << std::endl;
			ostr.unsetf(std::ios::left);
			for (int i = 0; i < m_height - 3; i++) {
				ostr << "|";
				ostr.width(m_width - 1);
				ostr.fill(' ');

				ostr << " |" << std::endl;
			}
			ostr << "+";
			for (int i = 0; i < m_width - 2; i++) {
				ostr << "-";
			}
			ostr << "+";
		}
	}
}