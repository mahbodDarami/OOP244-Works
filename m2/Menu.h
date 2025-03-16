/***********************************************************************
// OOP244 Project, milestone 2: tester program
//
// File	Menu.h
// Version 2.0
// Student Name and ID: Mahbod Darami - 117135244
// Date 2025-03-15
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
#include "constants.h"


namespace seneca {
    class Menu; // Forward declaration

    class MenuItem {
        char* menu_content;
        size_t menu_indent;
        size_t menu_indentSize;
        int menu_row;

        MenuItem(const char* content, size_t indent, size_t indentSize, int row);
        MenuItem(const MenuItem& other);
        MenuItem& operator=(const MenuItem& other);
        ~MenuItem();
        operator bool() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;

        friend class Menu;
        friend std::ostream& operator<<(std::ostream& os, const MenuItem& item);
    };

    class Menu {
    private:
        size_t menu_indent;
        size_t menu_indentSize;
        size_t menu_itemCount;
        MenuItem* menu_items[MaximumNumberOfMenuItems];
        MenuItem menu_title;
        MenuItem menu_exit;
        MenuItem menu_prompt;

        Menu(const Menu& other) = delete;
        Menu& operator=(const Menu& other) = delete;

    public:
        Menu(const char* title, const char* exitOption = "Exit", size_t indent = 0, size_t indentSize = 3);
        ~Menu();
        Menu& operator<<(const char* content);
        size_t select() const;
        friend size_t operator<<(std::ostream& ostr, const Menu& m);
    };

    std::ostream& operator<<(std::ostream& os, const MenuItem& item);
    size_t operator<<(std::ostream& ostr, const Menu& m);
}

#endif 
