// Name: [Mahbod Darami]
// Email: [mdarami@myseneca.ca]
// Student ID: [117135244]
// Date: [2025-02-15]


/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   Account::operator bool() const {
       return (m_number >= 10000 && m_number <= 99999 && m_balance >= 0);
   }
   Account::operator int()const {
       return m_number;
   }
   Account::operator double()const {
       return m_balance;
   }
   bool Account:: operator~()const {
       return  m_number == 0;
   }
   Account& Account::operator=(int value) {
       if (value < 10000 || value>99999) {
           this->setEmpty();
       }
       else if (m_number == 0) {
           m_number = value;
           
       }
       return *this;
   }
   Account& Account::operator=( Account& other) {
       if (m_number ==0 && other.operator bool()) {
           m_balance = other.m_balance;
           m_number = other.m_number;
           other.m_number = 0;
           other.m_balance = 0.0;
       }
       return *this;
   }
   Account& Account::operator+=(const double value) {
       if (value>=0 && operator bool()) {
           m_balance += value;
       }
       return *this;
   }
   Account& Account:: operator-=(const double value) {
       if (operator bool() && value >= 0 && (m_balance - value) >= 0) {
           m_balance -= value;
        }
       return *this;
   }
   Account& Account::operator<<(Account& right) {
       if (operator bool() && this!=&right && right.operator bool()) {
           m_balance += right.m_balance;
           right.m_balance = 0.0;
       }
       return *this;
   }
   Account& Account::operator>>(Account& right) {
       if (operator bool() && this != &right && right.operator bool()) {
           right.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }

   double operator+(const Account& left, const Account& right) {
       double sum = 0.0;
       if (right.operator bool() && left.operator bool()) {
            sum= left.operator double() + right.operator double();
       }
       return sum;
   }
   double operator+=(double& left,const Account& right) {
       left += right.operator double();
       return left;
   }

   /*
   Invalid Empty State
       
       An Account is in an invalid state if invalid information is 
       fed into the Account.In these types of situations
       the Account number is set to - 1 and the balance is set to 0. 
       The Account object in this case is rendered inactive 
       and can not be used anymore.
       
       New
       An Account is considered New or not set when it is just created
       and the Account number is not assigned yet.This 
       state of the Account class is flagged by setting the Account 
       number(m_number) to 0.
       
       Valid
       An Account is considered valid if the Account number is a 5 digit
       integer with a zero or positive balance.*/

 
}