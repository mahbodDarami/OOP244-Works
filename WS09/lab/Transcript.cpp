#include "Transcript.h"
#include "Utils.h"
//Student full name : Mahbod Darami
//student ID :: 117135244
// i have done all the answers of workshop by myself
namespace seneca{
	extern Utils ut;
	Transcript::Transcript(const char* studentName, size_t studentNumber): Marks() {
		s_name = ut.alocpy(studentName);
		s_number = studentNumber;
	}
	
	Transcript::Transcript(const Transcript& other)
		: Marks(other) {
		s_name = ut.alocpy(other.s_name);
		s_number = other.s_number;
	}

	Transcript& Transcript::operator=(const Transcript& other) {
		if (this != &other) {
			Marks::operator=(other); 
			delete[] s_name;
			s_name = ut.alocpy(other.s_name);
			s_number = other.s_number;
		}
		return *this;
	}
	Transcript::~Transcript() {
		delete[] s_name;
	}
	std::ostream& Transcript::display(std::ostream& ostr) const {
		ostr << s_name << " (" << s_number << ")\n";
		ostr << "--------------------------------------------------------------------------\n";
		Marks::display(ostr); 
		return ostr;
	}

}

