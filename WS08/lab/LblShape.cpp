//workshop 8
//written by Mahbod Darami - 117135244
//all codes written by me - 2025-03-25
#include "LblShape.h"
#include "Utils.h"
namespace seneca{
	const char* LblShape::label() const
	{
		return m_label;
	}
	LblShape::LblShape(const char* label)
	{
		ut.alocpy(m_label, label);
	}
	void LblShape::getSpecs(std::istream& is)
	{
		char buffer[256];
		is.get(buffer, 256, ',');
		is.ignore();
		ut.alocpy(m_label, buffer);
	}
	LblShape::~LblShape()
	{
		delete[] m_label;
	}
}

