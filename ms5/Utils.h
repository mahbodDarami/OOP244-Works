/***********************************************************************
// OOP244 Project, milestone 3:
//
// File	Billable.h
// Version 1.0
// Student Name and ID: Mahbod Darami - 117135244
// Date 2025-03-24
// Author Fardad
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
#include <cstddef> 
namespace seneca {
   class Utils {
   public:
      char* makeBillFileName(char* filename, size_t billNo)const;
      char* alocpy(const char* src)const;
      char* alocpy(char*& des, const char* src)const;
      char* strcpy(char* des, const char* src)const;
      int strlen(const char* str)const;
      bool isspace(char ch)const;
      bool isspace(const char* cstring)const;
      int getInt();
      int getInt(int min, int max); 
   };
   extern Utils ut;   // makes the ut object available where Utils.h is included
                     // to call a Utils function call it as follows
                     // ut.strcpy(des, src);
}

#endif // !SENECA_UTILS_H
