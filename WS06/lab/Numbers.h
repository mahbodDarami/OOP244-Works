/***********************************************************************
// OOP244 Workshop 6 lab: tester program
//Mahbod Darami - 117135244
//all codes by myself
// File	Numbers.h
// Version 1.0
// Date	2024/09/27
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>
namespace seneca {
    class Numbers {
        double* m_numbers;
        char* m_filename;   
        bool m_isOriginal;  
        int m_numCount;      
        bool isEmpty() const;  
        void setEmpty();       
        void setFilename(const char* filename);
        void sort();           
    public:
        Numbers();
        Numbers(const char* filename);
        Numbers(const Numbers& other);
        Numbers& operator=(const Numbers& other);
        ~Numbers();
        double average() const; 
        double max() const; 
        double min() const;
        int numberCount() const; 
        bool load();
        void save();
        Numbers& operator+=(double value);
        std::ostream& display(std::ostream& ostr) const;};
    std::ostream& operator<<(std::ostream& os, const Numbers& N);
    std::istream& operator>>(std::istream& istr, Numbers& N);}
#endif // !SENECA_NUMBERS_H_


