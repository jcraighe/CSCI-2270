#include <iostream> 
#include<string>

using namespace std;

struct Movie 
{
	string title;
	int ranking;
	int year;
	Movie* next;
};

Movie* makeNewMovie(string movieTitle, int movieRank, int movieYear);
int hashSum(string movieTitle, int hashTableSize);
Movie* movieSearch(string movieTitle, Movie* movies[], int hashTableSize);
bool insertMovie(string movieTitle, int movieRanking, int movieYear, Movie* movies[], int hashTableSize);


int main(int argc, char* argv[])
{
	int htSize = 10;
	Movie* movieList[htSize];

	for(int i = 0; i<htSize; i++)
	{
		movieList[i]= NULL;
	}

	if(insertMovie("Rick and Morty go to Anatomy Park", 10, 2015,movieList,10))
	{
		cout << "Rick and Morty go to Anatomy Park inserted" << endl;
	}
	if(insertMovie("Rick and Morty go to Anatomy Park", 10, 2015,movieList,10))
	{
		cout << "Rick and Morty go to Anatomy Park inserted" << endl;
	}

	Movie* searchedMovie = movieSearch("Rick and Morty go to Anatomy Park", movieList, 10);
	if(searchedMovie != NULL)
	{
		cout << "here: " << endl;
		cout << searchedMovie->title << endl;
		cout << searchedMovie->ranking << endl;
		cout << searchedMovie->year << endl;
	}
	else
	{
		cout << "Be gone Thot" << endl;
	}

	return 0;
}


Movie* makeNewMovie(string movieTitle, int movieRank, int movieYear)
{
	Movie* movie = new Movie;
	movie->title = movieTitle;
	movie->ranking = movieRank;
	movie->year = movieYear;
	movie->next = NULL;
	return movie;
}


int hashSum(string movieTitle, int hashTableSize)
{
	int letterSum = 0;
	for(int i = 0; i<movieTitle.length(); i++)
	{
		letterSum += int(movieTitle[i]);
	}
	return letterSum%hashTableSize;
}


bool insertMovie(string movieTitle, int movieRanking, int movieYear, Movie* movies[], int hashTableSize)
{
	int movieHashSum = hashSum(movieTitle, hashTableSize);
	if(movies[movieHashSum] == NULL)
	{
		Movie* movieToAdd = makeNewMovie(movieTitle,movieRanking,movieYear);
		movies[movieHashSum] = movieToAdd;
		return true;
	}
	else
	{
		Movie* movieTemp = movies[movieHashSum];
		bool inList = false;
		bool movieInserted = false;

		//check to see if new movie should go first
		if(movieTemp->title > movieTitle)
		{
			Movie* movieToAdd = makeNewMovie(movieTitle, movieRanking, movieYear);
			movieToAdd->next = movieTemp;
			movies[movieHashSum] = movieToAdd;
			movieInserted = true;
		}
		while(!inList && movieTemp != NULL && !movieInserted)
		{
			if(movieTemp->title == movieTitle)
			{
				//item in list
				inList = true;
			}
			else if(movieTemp->next != NULL && movieTemp->next->title > movieTitle || movieTemp->next == NULL)  //ignore error here
			{
				//insert 
				Movie* movieToAdd = makeNewMovie(movieTitle, movieRanking, movieYear);
				movieToAdd->next = movieTemp->next;
				movieTemp->next = NULL;
				movieInserted = true;
			}
			else
			{
				movieTemp = movieTemp->next;
			}
		}
		if(inList)
		{
			cout << "item already in hash table" << endl;
		}
		else if(!movieInserted)
		{
			cout << "I AM ERROR" << endl;
			return false;
		}
		else
		{
			//movie inserted
			return true;
		}
	}

}//end add


Movie* movieSearch(string movieTitle, Movie* movies[], int hashTableSize)
{
	int movieHashSum = hashSum(movieTitle, hashTableSize);
	bool movieFound = false;
	Movie* movieToFind = movies[movieHashSum];

	if(movies[movieHashSum] == NULL)
	{
		//nothing in array
		return NULL;
	}
	else
	{
		while(!movieFound && movieToFind != NULL)
		{
			if(movieToFind->title != movieTitle)
			{
				movieTitle = movieToFind->next->title;
			}
			else
			{
				movieFound = true;
			}

		}
	}
	return movieToFind;

}





