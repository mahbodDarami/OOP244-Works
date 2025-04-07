//Student Name and ID: Mahbod Darami - 117135244
// Date 2025-03-24
// Author Mahbod Darami
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// i got help for select() function from A.I

#include "Menu.h"
#include "Utils.h"
#include <cstring>
#include "constants.h"
#include <string> 

namespace seneca {
    extern Utils ut;

    MenuItem::MenuItem(const char* content, size_t indent, size_t indentSize, int row) {
        menu_content = ut.alocpy(content);
        menu_indent = indent;
        menu_indentSize = indentSize;
        menu_row = row;
    }

    MenuItem::MenuItem(const MenuItem& other) {
        menu_content = ut.alocpy(other.menu_content);
        menu_indent = other.menu_indent;
        menu_indentSize = other.menu_indentSize;
        menu_row = other.menu_row;
    }

    MenuItem& MenuItem::operator=(const MenuItem& other) {
        if (this != &other) {
            delete[] menu_content;
            menu_content = ut.alocpy(other.menu_content);
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
        return menu_content != nullptr;
    }

    std::ostream& MenuItem::display(std::ostream& ostr) const {
        for (size_t i = 0; i < menu_indent * menu_indentSize; ++i) {
            ostr << ' ';
        }
        if (menu_row >= 0) {
            ostr.width(2);
            ostr << menu_row << "- ";
        }
        ostr << menu_content;
        return ostr;
    }
    std::ostream& MenuItem::display(std::ostream& ostr, int temp) const {
        if (isEmpty()) {
            ostr << "??????????";
        }
        else {
            for (unsigned int i = 0; i < menu_indent; i++) {
                for (unsigned int j = 0; j < menu_indentSize; j++) {
                    ostr << " ";
                }
            }
            ostr << menu_content;
        }
        return ostr;
    }

    bool MenuItem::isEmpty() const
    {
       return menu_content == nullptr;
    }

   

    std::ostream& operator<<(std::ostream& os, const MenuItem& item) {
        return item.display(os);
    }

    Menu::Menu(const char* title, const char* exitOption, size_t indent, size_t indentSize) :
        menu_indent(indent),
        menu_indentSize(indentSize),
        menu_itemCount(0),
        menu_title(title, indent, indentSize, -1),
        menu_exit(exitOption, indent, indentSize, 0),
        menu_prompt("> ", indent, indentSize, -1) {

        for (size_t i = 0; i < MaximumNumberOfMenuItems; i++) {
            menu_items[i] = nullptr;
        }
    }


    Menu::~Menu() {
        for (size_t i = 0; i < menu_itemCount; i++) {
            delete menu_items[i];
            menu_items[i] = nullptr;
        }
    }

    Menu& Menu::operator<<(const char* content) {
        if (menu_itemCount < MaximumNumberOfMenuItems) {
            menu_items[menu_itemCount] = new MenuItem(content, menu_indent, menu_indentSize, int(menu_itemCount + 1));
            menu_itemCount++;
        }
        return *this;
    }

    size_t Menu::select() const
    {
        int select = 100;
        if (!menu_title.isEmpty()) {
            std::cout << menu_title << std::endl;

        }
        for (unsigned int i = 0; i < menu_itemCount; i++) {
            std::cout << *menu_items[i] << std::endl;

        }
        std::cout << menu_exit << std::endl;
        std::cout << menu_prompt;

        select = ut.getInt(0, menu_itemCount);

        return static_cast<size_t>(select);

    }


    size_t operator<<(std::ostream& ostr, const Menu& m) {
        if (&ostr == &std::cout) {
            return m.select();
        }
        return 0;
    }
}