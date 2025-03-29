#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H
#include "Shape.h"

//workshop 8
//written by Mahbod Darami - 117135244
//all codes written by me - 2025-03-25
namespace seneca {

   class LblShape :public Shape  {
      // Dynamically allocated label for the shape
       char* m_label = nullptr;
   protected:
      // Returns the label string for derived classes to access

       const char* label()const;
   public:
      // Default constructor
       LblShape() = default;

      // Constructor with label initialization
       LblShape(const char* label);
      // Copy constructor and assignment operator are deleted to prevent copying
      
       LblShape(const LblShape& other) = delete;
       LblShape& operator=(const LblShape& other) = delete;
      // Reads label specifications from input stream
       void getSpecs(std::istream& is) override;

      // Destructor to release dynamically allocated memory
       virtual ~LblShape();
   };
}

#endif // !SENECA_LABELEDSHAPE_H
