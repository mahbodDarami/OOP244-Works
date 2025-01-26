// Name: [Mahbod Darami]
// Email: [mdarami@myseneca.ca]
// Student ID: [117135244]
// Date: [2025-01-18]


/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_DMA_H
namespace seneca {
   struct Contact{
      char
         m_name[21],
         m_lastname[31];
      long long
         m_phoneNumber;
   };

   /// <summary>
   /// Receives an unknown number 
   /// of double numbers from the console and prints them in reverse order.
   /// </summary>
   void reverse();


   /// <summary>
   /// Creates a Contact compound type dynamically and gets its content from the console, then returns its address.
   /// </summary>
   /// <returns>Contact*: The address of the dynamically allocated Contact</returns>
   Contact* getContact();

   /// <summary>
   /// Prints a Contact in a line
   /// </summary>
   /// <param name="C">const reference of the Contact to be printed</param>
   void display(const Contact& cptr);

   void deallocate(Contact* cptr);
       /// <summary>
       /// Receives the address of a dynamically allocated Contact and removes it from memory.
       /// </summary>
       /// <param name="C">Contact*: The address of the Contact to be deallocated</param>

       void setEmpty(Contact& cptr);
   /// <summary>
   /// Empties the content of the Contact received by reference by setting the name and last name to empty strings and the phone number to zero.
   /// </summary>
   /// <param name="C">Contact&: Reference of a Contact to be emptied</param>


}
#endif // !SENECA_DMA_H

