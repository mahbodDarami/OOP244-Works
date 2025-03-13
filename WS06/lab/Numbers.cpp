/***********************************************************************
// OOP244 Workshop 6 lab: tester program
//Mahbod Darami - 117135244
//all codes by myself
// File	Numbers.cpp
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
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Numbers.h"

using namespace std;

namespace seneca {
    Numbers::~Numbers() {
        if (m_isOriginal && !isEmpty()) {
            save();
        }
        delete[] m_numbers;
        delete[] m_filename;
    }
    Numbers::Numbers(const Numbers& other) {
        setEmpty();
        m_isOriginal = false;
        if (!other.isEmpty()) {
            m_numCount = other.m_numCount;
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount; i++) {
                m_numbers[i] = other.m_numbers[i];
            }
        }
    }
    Numbers& Numbers::operator=(const Numbers& other) {
        if (this != &other) {
            delete[] m_numbers;
            m_numCount = other.m_numCount;
            if (m_numCount > 0) {
                m_numbers = new double[m_numCount];
                for (int i = 0; i < m_numCount; i++) {
                    m_numbers[i] = other.m_numbers[i];
                }
            }
            else {
                m_numbers = nullptr;
            }
        }
        return *this;
    }
    int Numbers::numberCount() const {
        ifstream file(m_filename);
        int count = 0;
        double temp;
        while (file >> temp) {
            count++;
        }
        return count;
    }
    bool Numbers::load() {
        if (m_numCount > 0) {
            m_numbers = new double[m_numCount];
            ifstream file(m_filename);
            int i = 0;
            while (file >> m_numbers[i]) {
                i++;
            }
            if (i != m_numCount) {
                delete[] m_numbers;
                setEmpty();
                return false;
            }
            return true;
        }
        return false;
    }
    void Numbers::save() {
        if (m_isOriginal && !isEmpty()) {
            ofstream file(m_filename);
            for (int i = 0; i < m_numCount; i++) {
                file << m_numbers[i] << endl;
            }
        }
    }
    Numbers& Numbers::operator+=(double value) {
        if (!isEmpty()) {
            double* temp = new double[m_numCount + 1];
            for (int i = 0; i < m_numCount; i++) {
                temp[i] = m_numbers[i];
            }
            temp[m_numCount] = value;
            m_numCount++;
            delete[] m_numbers;
            m_numbers = temp;
            sort();
        }
        return *this;
    }
    ostream& Numbers::display(ostream& ostr) const {
        if (isEmpty()) {
            ostr << "Empty list";
        }
        else {
            ostr << fixed << setprecision(2);
            ostr << "=========================\n";
            if (m_isOriginal) {
                ostr << m_filename << endl;
            }
            else {
                ostr << "*** COPY ***" << endl;
            }
            for (int i = 0; i < m_numCount; i++) {
                ostr << m_numbers[i];
                if (i < m_numCount - 1) {
                    ostr << ", ";
                }
            }
            ostr << "\n-------------------------\n";
            ostr << "Total of " << m_numCount << " number(s)\n";
            ostr << "Largest number:  " << max() << "\n";
            ostr << "Smallest number: " << min() << "\n";
            ostr << "Average:         " << average() << "\n";
            ostr << "=========================";
        }
        return ostr;
    }
    ostream& operator<<(ostream& os, const Numbers& N) {
        return N.display(os);
    }
    istream& operator>>(istream& istr, Numbers& N) {
        double value;
        if (istr >> value) {
            N += value;
        }
        return istr;
    }
}
