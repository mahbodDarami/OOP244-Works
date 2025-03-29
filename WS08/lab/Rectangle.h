#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"
//workshop 8
//written by Mahbod Darami - 117135244
//all codes written by me - 2025-03-25
namespace seneca {

   class Rectangle : public LblShape {
      // Width of the rectangle
      // Height of the rectangle
       int m_width;
       int m_height;
   public:
      // Default constructor
      
       Rectangle();
      // Constructor that initializes label, width, and height
       Rectangle(const char* label, int width, int height);

      // Draws the rectangle using the label, width, and height
       void draw(std::ostream& os)const override;

      // Gets specifications of the rectangle (label, width, height) from input
       void getSpecs(std::istream& is)override;
   };

}

#endif // !SENECA_RECTANGLE_H
