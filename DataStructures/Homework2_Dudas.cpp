// ==========================================
// Created: September 25, 2017
// @Chase Dudas
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


struct wordItem //creates the stuct & its variables
{
	string word;
	int count = 0;
};

void getStopWords (char *ignoreWordFileName, vector<string>& _vecIgnoreWords);
/*
 * Function name: getStopWords
 * Purpose: read stop word list from file and store into vector
 * 	@param ignoreWordFile - filename (the file storing ignore words)
 * 	@param _vecIgnoreWords - store ignore words from the file (pass by reference)
 * 	@return - none
 * Note: The number of words is fixed to 50
 */


bool isStopWord (string word, vector<string>& _vecIgnoreWords);
/*
 * Function name: isCommonWord
 * Purpose: to see if a word is a common word
 * 	@param word - a word (which you want to check if it is a common word)
 * 	@param _vecIgnoreWords - the vector type of string storing ignore/common words
 * 	@return - true (if word is a common words, or false (otherwise))
*/


void printTopN (wordItem wordItemList[], int topN);
/*
 * Function name: printTopN
 * Purpose: to print the top N high frequency words
 * 	@param wordItemList - a pointer that points to an array of wordItems
 * 	@param topN - the number of top frequency words to print
 * 	@return - none
*/

bool isArrayWord (string currentWord, wordItem* &trackerArray, int arrayCounter);
/*
 * Function name: isArrayWord
 * Purpose: check array to see if a word is anywhere in the array
 * 	@param currentWord - the word to check the array for
 * 	@param wordItem* &trackerArray - a pointer that points to the address of the array of wordItems
 * 	@return - true (if word is in the array, or false (otherwise))
*/

void dblArraySize (struct wordItem* &trackerArray, int arrayCounter, int arrayMax);
/*
 * Function name: dblArraySize
 * Purpose: to dynamically double an array if it is full
 * 	@param wordItem* &trackerArray - a pointer that points to the address of the array
 * 	@param arrayCounter - the current size of the array
 *  @param arrayMax - the new size of the array
 * 	@return - none
*/

void sortArray (wordItem* &trackerArray, int arrayCounter);
/*
 * Function name: BubbleSortArray
 * Purpose: to sort the array from greatest to least value
 * 	@param wordItem* &trackerArray - a pointer that points to the address of the array
 * 	@param arrayCounter - the current size of the array
 * 	@return - none
*/

void getTotalNumberNonStopWords (int totalWords);
/*
 * Function name: getTotalNumberNonCommonWords
 * Purpose: prints out the total number of non-common words
 * 	@param totalWords: the amount of non-common words
 * 	@return - none
*/


const int STOPWORD_LIST_SIZE = 50; 



int main(int argc, char* argv[]) 
{
	 vector<string> _vecIgnoreWords(STOPWORD_LIST_SIZE);

	 if (argc != 4) 
     {
         cout << "Usage: ";
         cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
         cout << endl;
         return 0;
     }

	 getStopWords (argv[3], _vecIgnoreWords); 

	 ifstream inToFile;
     string placeholder;
     int arrayMax = 100;
     int arrayCounter = 0;
     int doubledArrayCounter = 0;
     int totalNonCommon = 0;
     int wordsToOutput = atoi(argv[1]);

     wordItem* trackerArray = new wordItem[arrayMax];  

     inToFile.open (argv[2]); 
     
     if (inToFile.is_open())
     {

        while (inToFile >> placeholder)
        {
            if ((isStopWord(placeholder, _vecIgnoreWords) == false) && (isArrayWord(placeholder, trackerArray, arrayCounter) == false)) 
            {
                totalNonCommon = totalNonCommon + 1; 
                if (arrayMax > arrayCounter) 
                {
                    trackerArray[arrayCounter].word = placeholder;
                    trackerArray[arrayCounter].count = trackerArray[arrayCounter].count + 1; 
                }
                else 
                {
                    arrayMax = arrayMax * 2;
                    doubledArrayCounter = doubledArrayCounter + 1; 

                    dblArraySize(trackerArray, arrayCounter, arrayMax); 

                    trackerArray[arrayCounter].word = placeholder; 
                    trackerArray[arrayCounter].count = trackerArray[arrayCounter].count + 1; 
                }
                arrayCounter = arrayCounter + 1; 
            }
            else if((isStopWord(placeholder, _vecIgnoreWords) == false) && (isArrayWord(placeholder, trackerArray, arrayMax) == true)) 
            {
                totalNonCommon = totalNonCommon + 1; 
                for (int i = 0; i < arrayCounter; i++) 
                    {
                        if (placeholder == trackerArray[i].word)
                        {
                            trackerArray[i].count = trackerArray[i].count + 1;
                        }
                    }
            }
        }
        inToFile.close();
     }
     else
     {
         cout << "File not opened! Try again!" << endl;
     }

     sortArray(trackerArray, arrayCounter); 

     printTopN(trackerArray, wordsToOutput); 

	 cout << "#" << endl;
     cout << "Array doubled: " <<  doubledArrayCounter << endl;
     cout << "#" << endl;
     cout << "Unique non-stop words: " << arrayCounter << endl;
     cout << "#" << endl;
     getTotalNumberNonStopWords(totalNonCommon);

    return 0;
 }

 void getStopWords (char *ignoreWordFileName, vector<string>& _vecIgnoreWords)
{
     ifstream inFile;
     string data;
     inFile.open (ignoreWordFileName); 
     if (inFile.is_open())
     {
        
        while(inFile >> data) 
        {
            _vecIgnoreWords.push_back(data); 
        }
        inFile.close();
     }
     else
     {
         cout << "Stop Words File not opened! Try again!" << endl;
     }
    return;
 }

 bool isStopWord (string word, vector<string>& _vecIgnoreWords) 
 {
	 for(int i = 0; i < int(_vecIgnoreWords.size()); i++)
	 {
		 if( word == _vecIgnoreWords[i])
		 {
			 return true;
		 }
		 else
		 {
			 continue;
		 }
	 }
	 return false;
}
	
	
	/*	 
    if (find(_vecIgnoreWords.begin(), _vecIgnoreWords.end(), word) !=_vecIgnoreWords.end()) //help from cplusplus.com
    {
        return true;
    }
    else
    {
        return false;
    }
     */
 

bool isArrayWord (string currentWord, wordItem* &trackerArray, int arrayCounter) //help from cplusplus.com
 {
    for (int i = 0; i < arrayCounter; i++) 
    {
        if (trackerArray[i].word == currentWord)
        {
            return true;
        }
    }
    return false;
 }

void dblArraySize (struct wordItem* &trackerArray, int arrayCounter, int arrayMax) //helped from http://stackoverflow.com/questions/35108584/array-of-structs-doubling-algorithm-c
{
    wordItem* temp = new wordItem[arrayMax]; 
    
    for (int x = 0; x < arrayCounter; x++)
    {
        temp[x] = trackerArray[x]; 
    }

    delete [] trackerArray; 
    trackerArray = temp; 
}

void sortArray (wordItem* &trackerArray, int arrayCounter) 
{
    int i, j, flag = 1;
    wordItem temp;
    int numLength = arrayCounter; 
    for (i = 1; (i <= numLength) && flag; i++)
    {
        flag = 0;
        for (j=0; j < (numLength-1); j++)
        {
            if (trackerArray[j+1].count>trackerArray[j].count) 
            {
                temp = trackerArray[j];
                trackerArray[j] = trackerArray[j+1];
                trackerArray[j+1]=temp;
                flag = 1; 
            }
        }
    }
    return;
}

void printTopN (wordItem wordItemList[], int topN)
{
    for (int m = 0; m < topN; m++)
    {
         cout << wordItemList[m].count << " - " << wordItemList[m].word << endl;
    }
}

void getTotalNumberNonStopWords (int totalWords)
{
    cout <<"Total non-stop words: " << totalWords << endl;
}
