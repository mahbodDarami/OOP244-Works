// Name: [Mahbod Darami]
// Email: [mdarami@myseneca.ca]
// Student ID: [117135244]
// Date: [2025-01-13]


/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_MOVIE_H_
#define SENECA_MOVIE_H_
#endif // !SENECA_MOVIE_H_


namespace seneca {
	struct Movie {
		char m_title[128];
		int m_year;
		char m_rating[6];
		int m_duration;
		char m_genres[10][11];
		float m_consumerRating;
	};

	bool loadMovies();
	bool hasGenre(const Movie* mvp, const char genre[]);
	void displayMovie(const Movie* mvp);
	void displayMoviesWithGenre(const char genre[]);
}
