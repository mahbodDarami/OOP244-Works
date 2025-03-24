// i did all the codes by myself
   // Mahbod Darami - 117135244
#include "Professor.h"
#include <iostream>
#include "Employee.h"
#include "Utils.h"

using namespace std;
namespace seneca {
	Professor::Professor():Employee(),subjectName(nullptr), sectionNumbers(0){}
	Professor::Professor(const char* name,
		const char* subjectName, int sectionNumbers,
		size_t employeeNo, double salary):Employee(name, employeeNo,salary)
		,subjectName(ut.alocpy(subjectName)), 
		sectionNumbers(sectionNumbers){}
	Professor::~Professor() {
		delete[] subjectName;
	}
	double Professor::devPay() const {
		return (salary() * 0.01) * sectionNumbers;
	}
	istream& Professor::read(std::istream& istr) {
		Employee::read(istr);
		istr.ignore();
		char buffer[1024];
		istr.getline(buffer, 1024, ',');
		delete[] subjectName;
		subjectName = ut.alocpy(buffer);
		istr >> sectionNumbers;
		return istr;
	}
	ostream& Professor::write(ostream& ostr ) const {
		Employee::write(ostr);
		cout << " ";
		char subjectToPrint[21] = {};
		if (subjectName) ut.strcpy(subjectToPrint, subjectName, 20);
		ostr.width(20);
		ostr.fill(' ');
		ostr.setf(ios::left);
		ostr << subjectToPrint << " | ";
		ostr.unsetf(ios::left);
		ostr.width(5);
		ostr << sectionNumbers << " | ";
		ostr.fill(' ');
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr.width(8);
		ostr << devPay() << " |";
		ostr.unsetf(ios::right);
		return ostr;
	};
	std::ostream& Professor::title(std::ostream& ostr) const {
		Employee::title(ostr);
		ostr << " Teaching Subject     | Sec # | $Dev Pay |";
		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Professor& P) {
		return P.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Professor& P) {
		return P.read(istr);
	}

}