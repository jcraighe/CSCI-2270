#ifndef MOVIETREE_HPP
#define MOVIETREE_HPP
#include <string>

struct MovieNode
{
	int ranking;
	std::string title;
	int year;
	int quantity;
	MovieNode *parent;
	MovieNode *leftChild;
	MovieNode *rightChild;

	MovieNode()
	{
		ranking = -1;
		title = "NULL";
		year = -1;
		quantity = -1;
		parent = leftChild = rightChild = NULL;
	}

	MovieNode(int in_ranking, std::string in_title,int in_year, int in_quantity)
	{
		ranking = in_ranking;
		title = in_title;
		year = in_year;
		quantity = in_quantity;
		parent = leftChild = rightChild = NULL;
	}
};

class MovieTree
{
	public:
		MovieTree();
		~MovieTree();
		void printMovieInventory();
		void addMovieNode(int ranking, std::string title,int releaseYear, int quantity);
		void findMovie(std::string title);
		void rentMovie(std::string title);
		void deleteMovie(std::string title);
		void countMovies();
	private:
		MovieNode *search(MovieNode *node, std::string title);
		void deleteAll(MovieNode* node);
		void countMovies(MovieNode* node, int* c);
		MovieNode *root;
};

#endif // MOVIETREE_HPP