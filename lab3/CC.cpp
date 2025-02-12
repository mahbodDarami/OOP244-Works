#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
    void CC::prnNumber(unsigned long long no) const {
        cout << no / 1000000000000ull << " ";
        no %= 1000000000000ull;
        cout.fill('0');
        cout.width(4);
        cout.setf(ios::right);
        cout << no / 100000000ull << " ";
        no %= 100000000ull;
        cout.width(4);
        cout << no / 10000ull << " ";
        no %= 10000ull;
        cout.width(4);
        cout << no;
        cout.unsetf(ios::right);
        cout.fill(' ');
    }
    void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const {
        char lname[31]{};
        strcpy(lname, name, 30);
        cout << "| ";
        cout.width(30);
        cout.fill(' ');
        cout.setf(ios::left);
        cout << lname << " | ";
        prnNumber(number);
        cout << " | " << cvv << " | ";
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout.width(2);
        cout << expMon << "/" << expYear << " |" << endl;
        cout.unsetf(ios::right);
    }
     bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
        bool cond = true;  

        if (name == nullptr || strlen(name) <= 3) {
            return false;  
        }

        if (cardNo < 4000000000000000ULL || cardNo > 4099999999999999ULL) {
            cond = false;
        }

        if (cvv < 100 || cvv > 999) {
            cond = false;
        }

        if (expMon < 1 || expMon > 12) {
            cond = false;
        }

        if (expYear < 24 || expYear > 32) {
            cond = false;
        }

        return cond;  
    }
    void CC::set() {
        name = nullptr;
        expYear = 0;
        expMon = 0;
        cvv = 0;
        number = 0;
    }
    void CC::cleanUp() {
        freeMem(name);
        set();
    }
    bool CC::isEmpty() const {
        return name == nullptr;
    }
    void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
        cleanUp();
        if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
            if (alocpy(name, cc_name)) {
                number = cc_no;
                this->cvv = cvv;
                this->expMon = expMon;
                this->expYear = expYear;
            }
        }
    }
    void CC::display() const {
        if (isEmpty()) {
            cout << "Invalid Credit Card Record" << endl;
        }
        else {
            display(name, number, expYear, expMon, cvv);
        }
    }
}