//Student Name and ID: Mahbod Darami - 117135244
// Date 2025-03-24
// Author Mahbod Darami
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

#include "Billable.h"

namespace seneca {
    class Food : public Billable {
        bool m_ordered;      
        bool m_child;         
        char* m_customize;    

    public:
        Food();
        Food(const Food& other);
        Food& operator=(const Food& other);
        ~Food();
        std::ostream& print(std::ostream& ostr = std::cout) const override;
        bool order() override;
        bool ordered() const override;
        std::ifstream& read(std::ifstream& file) override;
        double price() const override;
    };
}

#endif // !SENECA_FOOD_H