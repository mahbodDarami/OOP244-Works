/***********************************************************************
// OOP244 Project, milestone 1: tester program
//
// File	Menu.h
// Version 1.0
// Student Name and ID: Mahbod Darami - 117135244
// Date 2025-03-10
// Author Fardad
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
i got help from chatgpt for this : private:
        MenuItem(const MenuItem& other);
        MenuItem& operator=(const MenuItem& other);
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>
#include "Utils.h"


namespace seneca {
    class MenuItem {
        char* menu_content;
        size_t menu_indent;
        size_t menu_indentSize;
        int menu_row;
    private:
        MenuItem(const MenuItem& other);
        MenuItem& operator=(const MenuItem& other);
    public:
        MenuItem(const char* content, size_t indent, size_t indentSize, int row);
        ~MenuItem();
        operator bool() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };
    std::ostream& operator<<(std::ostream& os, const MenuItem& item);
}

#endif 
