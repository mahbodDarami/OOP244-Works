// i did all the codes by myself
   // Mahbod Darami - 117135244
#include "Employee.h"
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
namespace seneca {

	class Professor : Employee {
		char* subjectName{};
		int sectionNumbers{};
		double devPay() const;
	public:
		Professor();
		Professor(const char* name, const char* subjectName, int sectionNumbers, size_t employeeNo, double salary);
		Professor(const Professor&) = delete;
		Professor& operator=(const Professor&) = delete;
		~Professor();
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;
		std::ostream& title(std::ostream& ostr = std::cout)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Professor& P);
	std::istream& operator>>(std::istream& istr, Professor& P);

}




#endif