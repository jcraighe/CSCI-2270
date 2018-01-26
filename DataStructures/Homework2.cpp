// ==========================================
// Created: August 23, 2016
// @author
//
// Description: Counts unique words in a file
// outputs the top N most common words
// ==========================================
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

#include <string>
#include <vector>

using namespace std;
// struct to store word + count combinations
struct wordItem
{
	string word;
	int count;
};


/*
* Function name: getStopWords
* Purpose: read stop word list from file and store into vector
* @param ignoreWordFile - filename (the file storing ignore words)
* @param _vecIgnoreWords - store ignore words from the file (pass by reference)
* @return - none
* Note: The number of words is fixed to 50
*/
void getStopWords(char *ignoreWordFileName, vector<string> &_vecIgnoreWords);


/*
* Function name: isStopWord
* Purpose: to see if a word is a stop word
* @param word - a word (which you want to check if it is a stop word)
* @param _vecIgnoreWords - the vector type of string storing ignore/stop words
* @return - true (if word is a stop word), or false (otherwise)
*/
bool isStopWord(string word, vector<string> &_vecIgnoreWords);


/*
* Function name: getTotalNumberNonStopWords
* Purpose: compute the total number of words saved in the words array
(including repeated words)
* @param list - an array of wordItems containing non-stopwords
* @param length - the length of the words array
* @return - the total number of words in the words array (including repeated
words multiple times)
*/
int getTotalNumberNonStopWords(wordItem list[], int length);


/*
* Function name: arraySort
* Purpose: sort an array of wordItems, increasing, by their count fields
* @param list - an array of wordItems to be sorted
* @param length - the length of the words array

*/
void arraySort(wordItem list[], int length);


/*
* Function name: printTopN
* Purpose: to print the top N high frequency words
* @param wordItemList - a pointer that points to a *sorted* array of wordItems
* @param topN - the number of top frequency words to print
* @return none
*/
void printTopN(wordItem wordItemList[], int topN);


const int STOPWORD_LIST_SIZE = 50;
const int INITIAL_ARRAY_SIZE = 100;
// ./a.out 10 HW2-HungerGames_edit.txt HW2-ignoreWords.txt

int main(int argc, char *argv[])
{
	vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);
	// verify we have the correct # of parameters, else throw error msg &
	
	if (argc != 4)
	{
		cout << "Usage: ";
		cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
		cout << endl;
		return 0;
	}

/* **********************************
1. Implement your code here.

Read words from the file passed in on the command line, store and
count the words.

2. Implement the six functions after the main() function separately.
********************************** */


	return 0;
}


void getStopWords(char *ignoreWordFileName, vector<string> &_vecIgnoreWords)
{
	return;
}


bool isStopWord(string word, vector<string> &_vecIgnoreWords)
{
	for( int i = 0; i < int(_vecIgnoreWords.size()); i++)
	{
		if(_vecIgnoreWords[i] == word)
		{
			return true;
		}
	}
	
	return false;
}


int getTotalNumberNonStopWords(wordItem list[], int length)
{
	int total = 0;
	
	for(int i = 0; i < length; i++)
	{
		total += list[i].count;
	}
	return total;
}


void arraySort(wordItem list[], int length)
{
	int j;
	wordItem temp;

	for (int i = 0; i < length; i++)
	{
		j = i;
		while (j > 0 && list[j].count < list[j-1].count)
		{ // move elements over until find the position for next element
			temp = list[j];
			list[j] = list[j-1];
			list[j-1] = temp;
			j--;
		}
	}
	//return;
}


void printTopN(wordItem wordItemList[], int topN)
{
	for(int i = 0; i < topN; i++)
	{
		cout << wordItemList[i].word << endl;
	}
}
