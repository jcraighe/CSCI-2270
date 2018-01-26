void HashTable::addWord(std::string word)
{
	int wordHashSum = getHash(word);
	if(hashTable[wordHashSum] == NULL)
	{
		wordItem* wordToAdd = new wordItem;
		wordToAdd->next = NULL;
		wordToAdd->count = 1;
		wordToAdd->word = word;
		hashTable[wordHashSum] = wordToAdd;
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
}