// Name: [Mahbod Darami]
// Email: [mdarami@myseneca.ca]
// Student ID: [117135244]
// Date: [2025-01-13]
// Description: [the main function file to exucate the program]

/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include "movie.h"
#include "utils.h"


using namespace std;
using namespace seneca;








int main() {
    bool done = false;
    char genre[128];
    loadMovies();
    cout << "Welcome to 50 top movies of all times \"genre\" search." << endl << endl;
    while (!done) {
        cout << "Enter the movie genre to start the search: ";
        cin >> genre;
        flushkeys();
        displayMoviesWithGenre(genre);
        cout << "Do another search? (Y)es: ";
        done = !yes();
        cout << endl;
    }
    cout << "Goodbye!" << endl;
    return 0;
}