//#ifndef MOVIE_HPP
//#define MOVIE_HPP
class Movie
{
	//function
	public:
		Movie();
		Movie(std::string _title, int _year, double _rating);
		
		std::string getTitle();
		void setTitle(std::string _title);
		
		int getYear();
		void setYear(int _year);
		
		double getRating();
		void setRating(double _rating);
	
	//instance variables
	private:
		std::string title;
		int year;
		double rating;
		
};
//#endif
