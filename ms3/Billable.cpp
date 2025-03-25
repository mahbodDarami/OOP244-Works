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
#include "Billable.h"
#include "Utils.h"

namespace seneca {
    Billable::Billable() : m_name(nullptr), m_price(0.0) {}
    Billable::Billable(const Billable& other) : m_name(nullptr), m_price(0.0) {
        ut.alocpy(m_name, other.m_name);
        m_price = other.m_price;
    }
    Billable& Billable::operator=(const Billable& other) {
        if (this != &other) {
            ut.alocpy(m_name, other.m_name);
            m_price = other.m_price;
        }
        return *this;
    }
    Billable::~Billable() {
        delete[] m_name;
    }
    void Billable::setPrice(double value) {
        m_price = value;
    }
    void Billable::name(const char* name) {
        ut.alocpy(m_name, name);
    }
    double Billable::price() const {
        return m_price;
    }
    Billable::operator const char* () const {
        return m_name;
    }
    double operator+(double money, const Billable& B) {
        return money + B.price();
    }
    double& operator+=(double& money, const Billable& B) {
        return money += B.price();
    }
}