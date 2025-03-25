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
#include "Food.h"
#include "Utils.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <cstring>

namespace seneca {
    Food::Food() : m_ordered(false), m_child(false), m_customize(nullptr) {}
    Food::Food(const Food& other) : Billable(other) {
        m_ordered = other.m_ordered;
        m_child = other.m_child;
        m_customize = ut.alocpy(other.m_customize);
    }
    Food& Food::operator=(const Food& other) {
        if (this != &other) {
            Billable::operator=(other); 
            m_ordered = other.m_ordered;
            m_child = other.m_child;
            ut.alocpy(m_customize, other.m_customize);
        }
        return *this;
    }

    Food::~Food() {
        delete[] m_customize;
    }
    std::ostream& Food::print(std::ostream& ostr) const {
        ostr.setf(std::ios::left);
        ostr.width(28);
        ostr.fill('.');
        ostr << (const char*)(*this); 
        ostr.fill(' '); 

        const char* portion = ".....";
        if (ordered()) {
            portion = m_child ? "Child" : "Adult";
        }
        ostr.width(5);  
        ostr << portion;
        ostr.setf(std::ios::fixed | std::ios::right);
        ostr.precision(2);
        ostr.width(7);
        ostr << price();
        if (&ostr == &std::cout && m_customize && m_customize[0] != '\0') {
            ostr << " >> " << m_customize;
        }
        ostr.unsetf(std::ios::left | std::ios::right);
        return ostr;
    }
    bool Food::order() {
        Menu portionMenu("Food Size Selection", "Back", 3);
        portionMenu << "Adult" << "Child";

        size_t choice = portionMenu.select();
        if (choice == 0) { 
            m_ordered = false;
            delete[] m_customize;
            m_customize = nullptr;
            return false;
        }

        m_child = (choice == 2); 
        m_ordered = true;
        std::cout << "Special instructions\n> ";
        char temp[256];
        std::cin.getline(temp, 256);
        if (temp[0] != '\0') {
            ut.alocpy(m_customize, temp);
        }
        else {
            delete[] m_customize;
            m_customize = nullptr;
        }

        return true;
    }
    bool Food::ordered() const {
        return m_ordered;
    }

    std::ifstream& Food::read(std::ifstream& file) {
        if (file) {
            char temp[1024] = {};
            double p;
            file.getline(temp, 1024, ',');
            file >> p;
            file.ignore(1000, '\n');

            if (file) {
                name(temp);
                setPrice(p);
                m_ordered = false;
                m_child = false;
                delete[] m_customize;
                m_customize = nullptr;
            }
        }
        return file;
    }
    double Food::price() const {
        double base = Billable::price();
        return (ordered() && m_child) ? base * 0.5 : base;
    }
}