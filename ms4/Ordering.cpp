//Student Name and ID: Mahbod Darami - 117135244
// Date 2025-03-24
// Author Mahbod Darami
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// line number 167 , os << std::string(indentWidth + labelWidth + amountWidth, '=') << std::endl; , is copy from A.I

#include "Ordering.h"
#include "Menu.h"
#include <cstring>
#include <iostream>
#include <iomanip>

namespace seneca {

    Ordering::Ordering(const char* drinkFilename, const char* foodFilename) {
        m_noOfDrinks = countRecords(drinkFilename);
        m_noOfFoods = countRecords(foodFilename);

        std::ifstream dfile(drinkFilename);
        std::ifstream ffile(foodFilename);

        if (dfile && ffile) {
            m_drinks = new Drink[m_noOfDrinks];
            m_foods = new Food[m_noOfFoods];

            size_t count = 0;
            while (count < m_noOfDrinks && m_drinks[count].read(dfile)) count++;
            if (count != m_noOfDrinks) {
                delete[] m_drinks; m_drinks = nullptr;
                delete[] m_foods; m_foods = nullptr;
                return;
            }

            count = 0;
            while (count < m_noOfFoods && m_foods[count].read(ffile)) count++;
            if (count != m_noOfFoods) {
                delete[] m_drinks; m_drinks = nullptr;
                delete[] m_foods; m_foods = nullptr;
            }
        }
    }

    Ordering::~Ordering() {
        delete[] m_foods;
        delete[] m_drinks;
        for (size_t i = 0; i < m_noOfBillItems; i++) {
            delete m_bill[i];
        }
    }

    Ordering::operator bool() const {
        return m_foods != nullptr && m_drinks != nullptr;
    }

    size_t Ordering::noOfBillItems() const {
        return m_noOfBillItems;
    }

    bool Ordering::hasUnsavedBill() const {
        return m_noOfBillItems > 0;
    }

    void Ordering::listFoods() const {
        std::cout << "List Of Avaiable Meals\n";
        std::cout << "========================================\n";
        for (size_t i = 0; i < m_noOfFoods; ++i) {
            m_foods[i].print(std::cout) << std::endl;
        }
        std::cout << "========================================\n";
    }

    void Ordering::listDrinks() const {
        std::cout << "List Of Avaiable Drinks\n";
        std::cout << "========================================\n";
        for (size_t i = 0; i < m_noOfDrinks; ++i) {
            m_drinks[i].print(std::cout) << std::endl;
        }
        std::cout << "========================================\n";
    }

    void Ordering::orderFood() {
        Menu m("Food Menu", "Back to Order", 2);
        for (size_t i = 0; i < m_noOfFoods; i++) {
            m << (const char*)m_foods[i];
        }
        size_t sel = m.select();
        if (sel > 0) {
            Food* f = new Food(m_foods[sel - 1]);
            if (f->order()) {
                m_bill[m_noOfBillItems++] = f;
            }
            else {
                delete f;
            }
        }
    }

    void Ordering::orderDrink() {
        Menu m("Drink Menu", "Back to Order", 2);
        for (size_t i = 0; i < m_noOfDrinks; i++) {
            m << (const char*)m_drinks[i];
        }
        size_t sel = m.select();
        if (sel > 0) {
            Drink* d = new Drink(m_drinks[sel - 1]);
            if (d->order()) {
                m_bill[m_noOfBillItems++] = d;
            }
            else {
                delete d;
            }
        }
    }

    void Ordering::printBill(std::ostream& os) const {
        double total = 0.0;
        billTitle(os);
        for (size_t i = 0; i < m_noOfBillItems; ++i) {
            m_bill[i]->print(os) << std::endl;
            total += m_bill[i]->price();
        }
        printTotals(os, total);
    }

    void Ordering::resetBill() {
        char filename[64];
        ut.makeBillFileName(filename, m_billNo);
        std::ofstream fout(filename);
        if (fout) {
            printBill(fout);
            std::cout << "Saved bill number " << m_billNo << std::endl;
            std::cout << "Starting bill number " << (m_billNo + 1) << std::endl;
        }
        for (size_t i = 0; i < m_noOfBillItems; ++i) {
            delete m_bill[i];
            m_bill[i] = nullptr;
        }
        m_noOfBillItems = 0;
        m_billNo++;
    }

    void Ordering::billTitle(std::ostream& os) const {
        os << "Bill # ";
        os.width(3);
        os.fill('0');
        os << m_billNo << " =============================" << std::endl;
        os.fill(' ');
    }

    void Ordering::printTotals(std::ostream& os, double total) const {
        constexpr double taxRate = 0.13;
        double tax = total * taxRate;
        double grandTotal = total + tax;

        os.setf(std::ios::fixed);
        os.precision(2);

        const int indentWidth = 21;    
        const int labelWidth = 13;     
        const int amountWidth = 6;     

        os << std::setw(indentWidth) << "" << std::left << std::setw(labelWidth) << "Total:" << std::right << std::setw(amountWidth) << total << std::endl;
        os << std::setw(indentWidth) << "" << std::left << std::setw(labelWidth) << "Tax:" << std::right << std::setw(amountWidth) << tax << std::endl;
        os << std::setw(indentWidth) << "" << std::left << std::setw(labelWidth) << "Total+Tax:" << std::right << std::setw(amountWidth) << grandTotal << std::endl;
        os << std::string(indentWidth + labelWidth + amountWidth, '=') << std::endl;
    }

    

    size_t Ordering::countRecords(const char* filename) const {
        std::ifstream file(filename);
        size_t count = 0;
        char ch;
        while (file.get(ch)) {
            if (ch == '\n') ++count;
        }
        return count;
    }
}
