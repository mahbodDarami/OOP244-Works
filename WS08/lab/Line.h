#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include "LblShape.h"
//workshop 8
//written by Mahbod Darami - 117135244
//all codes written by me - 2025-03-25
namespace seneca {

   class Line: public LblShape {
       // Length of the line
       int m_length;
   public:
      // Default constructor
       Line();

      // Constructor that initializes label and length
     
       Line(const char* label, int length);
      // Draws the line, using the label and length
       void draw(std::ostream& os) const override;

      // Gets specifications of the line (label and length) from input
       void getSpecs(std::istream& is) ;
   };

}

#endif // !SENECA_LINE_H
