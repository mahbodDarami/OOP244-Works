/***********************************************************************
// OOP244 Project, milestone 1: tester program
//
// File	Menu.cpp
// Version 1.0
// Student Name and ID: Mahbod Darami - 117135244
// Date 2025-03-10
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

#include "Menu.h"
#include "Utils.h"
#include <cstring>
#include "constants.h"

namespace seneca {
    extern Utils ut;
    MenuItem::MenuItem(const char* content, size_t indent, size_t indentSize, int row) {
        menu_content = nullptr;
        menu_indent = 0;
        menu_indentSize = 0;
        menu_row = -1;
        if (content && std::strlen(content) > 0 && !ut.isspace(content) &&
            indent <= 4 && indentSize <= 4 && row < int(MaximumNumberOfMenuItems)) {
            menu_content = ut.alocpy(content);
            menu_indent = indent;
            menu_indentSize = indentSize;
            menu_row = row;
        }}
    MenuItem::MenuItem(const MenuItem& other) {
        menu_content = nullptr;
        if (other.menu_content) {
            menu_content = ut.alocpy(other.menu_content);}
        menu_indent = other.menu_indent;
        menu_indentSize = other.menu_indentSize;
        menu_row = other.menu_row;
    }
    MenuItem& MenuItem::operator=(const MenuItem& other) {
        if (this != &other) {
            delete[] menu_content;
            menu_content = nullptr;
            if (other.menu_content) {
                menu_content = ut.alocpy(other.menu_content);
            }
            menu_indent = other.menu_indent;
            menu_indentSize = other.menu_indentSize;
            menu_row = other.menu_row;
        }
        return *this;
    }

    MenuItem::~MenuItem() {
        delete[] menu_content;
    }

    MenuItem::operator bool() const {
        return menu_content != nullptr && !ut.isspace(menu_content);
    }


    std::ostream& MenuItem::display(std::ostream& ostr) const {
        if (*this) {
            for (size_t i = 0; i < menu_indent * menu_indentSize; ++i) {
                ostr << ' ';
            }
            if (menu_row >= 0) {
                ostr.width(2);
                ostr << menu_row << "- ";
            }
            ostr << "The Menu Item";  
        
        }
        else {
            ostr << "??????????";}
        return ostr;
    }

    std::ostream& operator<<(std::ostream& os, const MenuItem& item) 
    {
        return item.display(os);}

}
