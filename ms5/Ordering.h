//Student Name and ID: Mahbod Darami - 117135244
// Date 2025-03-24
// Author Mahbod Darami
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.

#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H

#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "constants.h"
#include "Utils.h"
#include <fstream>
#include <iostream>

namespace seneca {
    class Ordering {
        Food* m_foods{};
        Drink* m_drinks{};
        Billable* m_bill[MaximumNumberOfMenuItems]{};
        size_t m_noOfFoods{};
        size_t m_noOfDrinks{};
        size_t m_noOfBillItems{};
        size_t m_billNo{ 1 };

        void billTitle(std::ostream& os) const;
        void printTotals(std::ostream& os, double total) const;
        size_t countRecords(const char* filename) const;
    public:
        Ordering(const char* drinkFilename, const char* foodFilename);
        ~Ordering();

        operator bool() const;
        size_t noOfBillItems() const;
        bool hasUnsavedBill() const;

        void listFoods() const;
        void listDrinks() const;
        void orderFood();
        void orderDrink();
        void printBill(std::ostream& os) const;
        void resetBill();
    };
}

#endif
