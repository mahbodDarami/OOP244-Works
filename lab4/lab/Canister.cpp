// Name: [Mahbod Darami]
// Email: [mdarami@myseneca.ca]
// Student ID: [117135244]
// Date: [2025-02-10]


/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <istream>
#include "cstr.h"  
#include "Canister.h"
using namespace std;
namespace seneca {
    Canister::Canister() {
       /* Height and diameter: 13.0 x 10.0 centimeters
            Content volume : 0
            Content name : nullptr*/
        m_contentName = nullptr;
        m_diameter = 10; // in centimeters 
        m_height = 13.0; // in centimeters
         m_contentVolume = 0;  // in CCs
    }
   /* With a content name only
        With height, diameter, and content name(if the name is not provided, it should default to nullptr)*/
    Canister::Canister(const char* contentName) {
        /*Sets the attributes to their default values.
            Dynamically allocates and copies the contentName into memory pointed to by m_contentName(use the provided alocpy function).*/
        m_contentName = nullptr;
        m_diameter = 10; // in centimeters 
        m_height = 13.0; // in centimeters
        m_contentVolume = 0;  // in CCs
        /*des = new char[strlen(src) + 1];
        strcpy(des, src);*/
        alocpy(m_contentName, contentName);
    }
    /*Use usable method and alocpy function in this logic*/

        /*Logic
        Sets the content name and the content value to their default values.
        Sets the height and diameter attributes to the corresponding incoming arguments.
        If the object is usable(use the private method) :
        Dynamically allocates and copies the contentName into memory pointed to by m_contentName(use alocpy).*/
    Canister::Canister(double height, double diameter, const char* contentName ) {
        m_contentName = nullptr;
        m_diameter = diameter; // in centimeters 
        m_height = height; // in centimeters
        m_contentVolume = 0;  // in CCs
        
        alocpy(m_contentName, contentName);
        
    }
    Canister::~Canister() {
        //Deallocates the dynamic memory pointed to by the content name attribute(use freemem).
        freeMem(m_contentName);
    }
    Canister& Canister:: clear() {
        freeMem(m_contentName);
        m_contentVolume = 0.0;
        return *this;
    }
    Canister& Canister::setContent(const char* contentName) {
        if (contentName!=nullptr && usable()) {
            if (isEmpty() || m_contentName == nullptr) {
                alocpy(m_contentName, contentName);  
            }
            else if (m_contentName != nullptr && !hasSameContent(m_contentName)) {
                setToUnusable();
            }
        }
        return *this;
    }

    Canister& Canister::pour(double quantity) {
        if (usable()) {
            if (quantity > 0 && (quantity + volume()) <= capacity()){
                    m_contentVolume += quantity;  
            }
            else {
                setToUnusable();
            }
        }
        return *this;
    }
    Canister& Canister::pour(Canister& can) {
        
        if (usable()) {

            if (hasSameContent(can) || isEmpty()) {
                double diffrence = capacity() - volume();
                if (can.volume() > diffrence) {
                    can.m_contentVolume -= diffrence;
                    m_contentVolume += diffrence;

                }
                else {
                    m_contentVolume += can.volume();
                    can.m_contentVolume = 0;

                }
                if (m_contentName == nullptr) {
                    alocpy(m_contentName, can.m_contentName);
                }
                else if (!hasSameContent(can)) {
                    setToUnusable();
                }
            }
            else{
                setToUnusable();
            }
                
           
        }
        return *this;

    }



   const double PI = 3.14159265;
   

   bool Canister::isEmpty() const {
      return m_contentVolume < 0.00001;
   }

   bool Canister::usable() const
   {
      return m_height >= 10 && m_height <= 40 && m_diameter >= 10 && m_diameter <= 30;
   }

   void Canister::setToUnusable(){
      freeMem(m_contentName);
      m_diameter = m_height = -1.0;
   }

   double Canister::capacity() const {
      return PI * (m_height-0.267) * (m_diameter/2) * (m_diameter / 2);
   }

      bool Canister::hasSameContent(const Canister& C)const {
      return m_contentName && C.m_contentName && strcmp(m_contentName, C.m_contentName) == 0;
   }

   double Canister::volume() const {
      return m_contentVolume;
   }

   std::ostream& Canister::display() const {
      cout.setf(ios::fixed);
      cout.precision(1);
      cout.width(7);
      cout << capacity() << "cc (";
      cout.width(4);
      cout << m_height << "x";
      cout.width(4);
      cout << m_diameter << ") Canister";
      if (!usable()) {
         cout << " is  Unusable   recycle!";
      }
      else {
         cout << " of ";
         cout.width(7);
         cout << volume() << "cc   " << (m_contentName?m_contentName:"Sanetized and Empty");
      }
      return cout;
   }
}
