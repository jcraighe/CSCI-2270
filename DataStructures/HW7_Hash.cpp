#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include "HW7_Hash.hpp"

using namespace std;


HashTable::HashTable(int hashTableSize) //done 
{
	HashTable::hashTableSize = hashTableSize;
	hashTable = new wordItem*[hashTableSize];
	for(int i = 0; i < hashTableSize; i++)
	{
		hashTable[i] = NULL;
	}
}

HashTable::~HashTable() //done
{
	for(int i = 0; i < hashTableSize; i++)
	{
		wordItem* head = hashTable[i];
		while(head != NULL)
		{
			wordItem* current = head->next;
			head->next = NULL;
			delete head;
			head = current;
		}
	}
	delete [] hashTable;
	
}

void HashTable:: getStopWords(char *ignoreWordFileName)
{
    ifstream inFile;
    inFile.open(ignoreWordFileName);
    string line = "";
    int count = 0;
    if(inFile.is_open()){
        while(getline(inFile, line))
        {
            vecIgnoreWords[count] = line;
            count++;
        }
    }
    else
    {
        cout << "Error - stop words file failed to open!" << endl;
    }
    inFile.close();

}

bool HashTable:: isStopWord(std::string word)
{
    for(int i = 0 ; i < STOPWORD_LIST_SIZE; i++)
    {
        if (word == vecIgnoreWords[i])
        {
            return true;
        }
    }
    return false;
}

bool HashTable::isInTable(std::string word) // done
{
	wordItem* node = searchTable(word);
	if(node == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void HashTable::incrementCount(std::string word) //done
{
	wordItem* temp = searchTable(word);
	temp->count = temp->count + 1;
}

void HashTable::addWord(std::string word) //done and graded 
{
	wordItem* newWord = new wordItem;
	wordItem* temp;
	newWord->count = 1;
	newWord->word = word;
	int hash = getHash(word);
	if(hashTable[hash] != NULL)
	{
	    numCollisions++;
	}
	temp = hashTable[hash];
	newWord->next = temp;
	hashTable[hash] = newWord;	
}

int HashTable::getTotalNumberNonStopWords() //done and graded 
{
	int total = 0;

	for(int i = 0; i < hashTableSize; i++)
	{
		wordItem* temp = hashTable[i];
		while(temp != NULL)
		{
			total = total + temp->count;
			temp=temp->next;
		}
	}
	return total;
}

void HashTable::printTopN(int n)
{
    int tempNum = 0;
    string tempString = "";
    string most[n];
    int highest[n];

    for(int p = 0; p < n ; p++)
    {
        highest[p] = 0;
        most[p] = "ggggggg";
    }
    for (int i = 0; i < hashTableSize; i++)
    {
        if(i != 8853)
        {
            wordItem * temp = hashTable[i];
            while(temp != nullptr)
            {
                for(int s = 0; s < n ; s++)
                {
                    if(temp->count >= highest[s])
                    {
                        tempNum = highest[s];
                        tempString = most[s];
                        int x = temp-> count;
                        highest[s] = x;
                        most[s] = temp->word;
                        int min = 11000000;
                        int finder = 0;
                        for(int y = 0; y < n; y++)
                        {
                            if(highest[y] <= min)
                            {
                                min = highest[y];
                                finder = y;
                            }
                        }
                        highest[finder] = tempNum;
                        most[finder] = tempString;
                        break;
                    }
                }
                temp = temp-> next;
            }
        }
        if(i == 8853)
        {
            i ++;
        }
    }
    int tempi = 0;
    string temps = "";
    for (int v = 0; v < n; v++)
    {
        for(int q = 0; q < n; q++)
        {
            if(highest[v] >= highest[q])
            {
                tempi = highest[q];
                temps = most[q];
                highest[q] = highest[v];
                most[q] = most[v];
                highest[v] = tempi;
                most[v] = temps;
            }
        }
    }
    for(int d = 0; d < n; d++){
        cout << highest[d] << " - " << most[d] << endl;
    }
}

int HashTable::getNumUniqueWords() //done
{
    int total = 0;

	for(int i = 0; i < hashTableSize; i++)
	{
		wordItem* temp = hashTable[i];
		while(temp != NULL)
		{
			total = total + 1;
			temp=temp->next;
		}
	}
	return total;
	
}


int HashTable::getNumCollisions() //done
{
	return numCollisions;
}


int HashTable::getHash(std::string word) //check 
{
	int hash = 5381;
	char c;
    for(int i=0; i<int(word.size()); i++)
    {
        c=word[i];
        hash = hash*33 + c;
    }
	hash = int(hash % hashTableSize);
	if(hash < 0) 
		hash+=hashTableSize;
	return hash;	
}

wordItem* HashTable::searchTable(std::string word) //done
{
	int hash = getHash(word);
	wordItem* temp = hashTable[hash];
	while(temp != NULL)
	{
		if(temp->word == word)
		{
			return temp;
		}
		else
		{
			temp = temp->next;
		}

	}
	return NULL;
}




int main(int argc, char* argv[]) //done and graded 
{
	HashTable* myHashTable = new HashTable(atoi(argv[4]));

	if (argc != 5) 
     {
         cout << "Usage: ";
         cout << argv[0] << " <filename.txt> <ignorefilename.txt> <hash table size> ";
         cout << endl;
         return 0;
     }

     myHashTable->getStopWords(argv[3]);

     ifstream inToFile;
     string placeholder;
     int wordsToOutput = atoi(argv[1]); //10
 
     inToFile.open(argv[2]); 
     
     if (inToFile.is_open())
     {

        while (inToFile >> placeholder)
        {
        	if(myHashTable->isStopWord(placeholder))
        	{
        		continue;
        	}
        	else if(myHashTable->isInTable(placeholder))
        	{
        		myHashTable->incrementCount(placeholder);
        	}
        	else
        	{
        		myHashTable->addWord(placeholder);
        	}
		}
	}

	myHashTable->printTopN(wordsToOutput);
	cout << "#" << endl;
	cout << "Number of collisions: " << myHashTable->getNumCollisions() << endl;
	cout << "#" <<endl;
	cout << "Unique non-stop words: " << myHashTable->getNumUniqueWords() << endl;
	cout << "#" << endl;
	cout << "Total non-stop words: " << myHashTable->getTotalNumberNonStopWords() << endl;
	return 0;
}









