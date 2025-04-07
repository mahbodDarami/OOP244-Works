/***********************************************************************
// OOP244 Project, milestone 2: tester program
//
// File	utils.cpp
// Version 2.0
// Student Name and ID: Mahbod Darami - 117135244
// Date 2025-03-15
// Author Fardad
// Description
//I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"
using namespace std;
namespace seneca {
   Utils ut;

   char* Utils::makeBillFileName(char* filename, size_t billNo)const {
       char billFileName[21] = "bill_";
       size_t temp = billNo;
       int cnt = 5;
       int length;
       // Calculate the number of digits
       do {
           cnt++;
           temp /= 10;
       } while (temp > 0);
       length = cnt;
       // Convert each digit to character from the end
       while (billNo > 0) {
           billFileName[--cnt] = (billNo % 10) + '0';
           billNo /= 10;
       }
       // Handle the case when billNo is 0
       if (billFileName[cnt - 1] == '\0') {
           billFileName[--cnt] = '0';
       }
       // Attach .txt to the end of the file name
       for (int i = 0; ".txt"[i]; i++) {
           billFileName[length++] = ".txt"[i];
       }
       billFileName[length] = '\0';
       strcpy(filename, billFileName);
       return filename;
   }

   char* Utils::alocpy(const char* src) const{
      char* des{};
      return alocpy(des, src);
   }

   char* Utils::alocpy(char*& des, const char* src)const {
      delete[] des;
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return des;
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   bool Utils::isspace(char ch)const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   bool Utils::isspace(const char* cstring) const{
      while (cstring && isspace(*cstring)) {
         cstring++;
      }
      return cstring && *cstring == 0;
   }
   int Utils::getInt()
   {
       int input;
       bool valid = false;

       do {

           if (cin.peek() == '\n') {
               cin.ignore();
               cout << "You must enter a value: ";
           }
           else { // always enter in the first loop
               cin >> input;


               if (cin.fail()) {
                   cin.clear();
                   cout << "Invalid integer: ";
               }
               else if (cin.peek() != '\n') {
                   cout << "Only an integer please: ";
                   cin.clear();
               }
               else {
                   valid = true;
               }

               cin.ignore(1000, '\n');
           }
       } while (!valid);
       return input;
   }

   int Utils::getInt(int min, int max) {
       bool result = false;
       int input = 100;

       do {
           input = getInt();
           if (input >= min && input <= max) {
               result = true;
           }
           else {
               cout << "Invalid value: [" << min << "<= value <=" << max << "], try again: ";
           }
       } while (!result);

       return input;
   }

}