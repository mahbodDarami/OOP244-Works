// Name: [Mahbod Darami]
// Email: [mdarami@myseneca.ca]
// Student ID: [117135244]
// Date: [2025-02-15]


/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool() const;
        operator int()const;
        operator double()const;
        bool operator~()const;
        Account& operator=(int value);
        Account& operator=( Account& other);
        Account& operator+=(const double value);
        Account& operator-=(const double value);
        Account& operator<<(Account& right);
        Account& operator>>(Account& right);
        
    };
    double operator+(const Account& left, const Account& right);
    double operator+=(double& left, const Account& right);
}
#endif // SENECA_ACCOUNT_H_