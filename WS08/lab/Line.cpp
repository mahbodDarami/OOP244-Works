#include "Line.h"
#include <iostream>
//workshop 8
//written by Mahbod Darami - 117135244
//all codes written by me - 2025-03-25
namespace seneca {
    Line::Line() : m_length(0) {}

    Line::Line(const char* label, int length) : LblShape(label), m_length(length) {

    }

    void Line::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }

    void Line::draw(std::ostream& os) const {
        if (m_length > 0 && label() != nullptr) {
            os << label() << std::endl;
            for (int i = 0; i < m_length; i++) {
                os << '=';
            }
            
        }
    }
}