// ==========================================
// Created: August 23, 2016
// @author
// CSCI-2270 CU-Boulder
// Description: Counts unique words in a file
// outputs the top N most common words
// ==========================================
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;
 
// struct to store word + count combinations
    struct wordItem{
        string word;
        int count = 1;
    };
 
/*
* Function name: getStopWords
* Purpose: read stop word list from file and store into vector
* @param ignoreWordFile - filename (the file storing ignore words)
* @param _vecIgnoreWords - store ignore words from the file (pass by reference)
* @return - none
* Note: The number of words is fixed to 50
*/
void getStopWords(char *ignoreWordFileName, vector<string>& _vecIgnoreWords);
/*
* Function name: isCommonWord
* Purpose: to see if a word is a common word
* @param word - a word (which you want to check if it is a common word)
* @param _vecIgnoreWords - the vector type of string storing ignore/common words
* @return - true (if word is a common word), or false (otherwise)
*/
bool isCommonWord(string word, vector<string>& _vecIgnoreWords);
/*
* Function name: printTopN
* Purpose: to print the top N high frequency words
* @param wordItemList - a pointer that points to an array of wordItems
* @param topN - the number of top frequency words to print
* @return none
*/
void printTopN(wordItem wordItemList[], int topN, int size);
/*Function Name: getTotalNumberNonCommon Words
 * Purpose: get the total number of non common words
 *@param wordListHungerGames - word list of the hunger games
 * @param size - size of the array
 * return number of words
 */
int getTotalNumberNonCommonWords(wordItem wordListHungerGames[], int size);
 
 
const int STOPWORD_LIST_SIZE = 50;
 
 
 
    int main(int argc, char* argv[]){
    //verify we have the correct # of parameters, else throw error msg & return
        if (argc != 4){
            cout << "Usage: ";
            cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
            cout << endl;
            return 0;
            }
           
        vector<string> _vecIgnoreWords(STOPWORD_LIST_SIZE);
        //get all the information from command line arguments, filename, number of topN words, ignore file
        int numberOfWords = atoi(argv[1]);
        string fileName = argv[2];
        string fileNameIgnore = argv[3];
       
        //allow for getStopWords to be called by converting from string to char*
        char* p = new char[fileNameIgnore.length() + 1];
        memcpy(p, fileNameIgnore.c_str(), fileNameIgnore.length()+1);
        getStopWords(p, _vecIgnoreWords);
        //open the hunger games wordlist file
        ifstream infile;
        infile.open(fileName.c_str());
   
       
        //count how many times we double the array, declare the size of the array, prepare to read in from the file and add it to the wordListHungerGames array of struct
        int dcounter = 0;
        int size = 100;
        wordItem *wordListHungerGames = new wordItem[size];
        wordItem *wordListTemp = new wordItem[size];
        int i = 0;
        string temp;
        int a = 0;
        while(infile >> temp){
            if(i==size){
                wordListTemp = new wordItem[size];
               
                for(int k = 0; k<size;k++){
                    wordListTemp[k] = wordListHungerGames[k];
                }
                delete[] wordListHungerGames;
                size=size*2;
                wordListHungerGames = new wordItem[size];
                for(int k = 0; k < size/2; k++){
                    wordListHungerGames[k] = wordListTemp[k];
                }
                delete[] wordListTemp;
                dcounter++;
        }
        if(!isCommonWord(temp, _vecIgnoreWords)){
            for(int j = 0; j<i; j++){
                if(temp == wordListHungerGames[j].word){
                    wordListHungerGames[j].count++;
                    a=1;
                    break;
                }
            }
            if(a==0){
                wordListHungerGames[i].word = temp;
                i++;
            }
            a=0;
        }
       
    }
    //close the file and output everything to command line
    infile.close();
    int wordscount = getTotalNumberNonCommonWords(wordListHungerGames, size);
    printTopN(wordListHungerGames, numberOfWords, size);
    cout << "#" << endl;
    cout << "Array doubled: " << dcounter << endl;
    cout << "#" << endl;
    cout << "Unique non-common words: " << i << endl;
    cout << "#" << endl;
    cout << "Total non-common words: " << wordscount << endl;
    delete[] wordListHungerGames;
    //delete the array
}  
 
 
void getStopWords(char *ignoreWordFileName, vector<string>& _vecIgnoreWords){
        ifstream fileIgnore;
        string line;
        fileIgnore.open(ignoreWordFileName);
        if(fileIgnore.is_open()){
            while(getline(fileIgnore, line)){
                _vecIgnoreWords.push_back(line);
            }
        }
        fileIgnore.close();
    return;
    }
 
bool isCommonWord(string word, vector<string>& _vecIgnoreWords){
        if(find(_vecIgnoreWords.begin(), _vecIgnoreWords.end(), word) != _vecIgnoreWords.end()){
            return true;
            }
           
        else{
            return false;
            }
    }
   
int getTotalNumberNonCommonWords(wordItem wordListHungerGames[], int size)
{
    int total = 0;
    for(int i = 0; i < 7682; i++)
    {
        int newsize = wordListHungerGames[i].count;
        for(int j = 0; j < newsize; j++)
        {
            total++;
        }
    }
    return total;
}
 
void printTopN(wordItem wordItemList[], int topN, int size){
    int q = 0;
    int tempnum = 1;
    for(int i = 0; i < topN; i++){
        for(int j = 0; j < size; j++){
            if (wordItemList[j].count > tempnum){
                q = j;
                tempnum = wordItemList[j].count;
            }
        }
        cout << wordItemList[q].count << " - " << wordItemList[q].word << endl;
        wordItemList[q].count = 0;
        tempnum = 1;
        }
    }
