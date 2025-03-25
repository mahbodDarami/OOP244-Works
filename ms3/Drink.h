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