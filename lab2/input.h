// Name: [Mahbod Darami]
// Email: [mdarami@myseneca.ca]
// Student ID: [117135244]
// Date: [2025-01-18]


/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_INPUT_H
#define SENECA_INPUT_H
namespace seneca {
   /// <summary>
   /// Performs a foolproof integer entry from the console.
   /// </summary>
   /// <returns>The integer read from the console</returns>
   int getInt();

   /// <summary>
   /// Performs a foolproof integer entry from the console with an upper and lower acceptable limit.
   /// </summary>
   /// <param name="minVal">int: Minimum acceptable value</param>
   /// <param name="maxVal">int: Maximum acceptable value</param>
   /// <returns>The integer read from the console</returns>
   int getInt(int minVal, int maxVal);

   /// <summary>
   /// Performs an integer entry from the console only if the values are within the acceptable limits.
   /// </summary>
   /// <param name="number">A reference to an integer number to be read from the console</param>
   /// <param name="minVal">int: Minimum acceptable value</param>
   /// <param name="maxVal">int: Maximum acceptable value</param>
   /// <returns>bool: true if the number is successfully read, or false otherwise</returns>
   bool getInt(int &number, int minVal, int maxVal);

}
#endif // !SENECA_IO_H


