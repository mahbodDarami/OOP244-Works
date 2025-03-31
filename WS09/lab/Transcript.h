/***********************************************************************
// OOP244 workshop 9, Transcript module
//Student full name : Mahbod Darami
//student ID :: 117135244
// i have done all the answers of workshop by myself
// File	Transcript.h
// Version 1.0
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"
namespace seneca {
   class Transcript :public Marks{
      // character pointer student name
       char* s_name{};
      // unsigned integer or size_t student number
       size_t s_number{};
   public:
      // Constructor
       Transcript(const char* s_name, size_t s_number);
      // Rule of Three
       Transcript(const Transcript& other);
       Transcript& operator=(const Transcript& other);
      // Destructor
       ~Transcript();
       std::ostream& display(std::ostream& ostr = std::cout)const;
   };
}
#endif // !SENECA_TRANSCRIPT_H


