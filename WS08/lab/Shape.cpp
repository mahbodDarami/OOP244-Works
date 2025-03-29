//workshop 8
//written by Mahbod Darami - 117135244
//all codes written by me - 2025-03-25

#include "Shape.h"

namespace seneca {
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape)
	{
		shape.draw(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Shape& shape)
	{
		shape.getSpecs(istr);
		return istr;
	}
}
