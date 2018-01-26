#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include "HW7_Hash.hpp"

using namespace std;


void HashTable::printTopN(int n)
{
    wordItem* arr[n]; //array of top n word structs
    wordItem* set;
    set->count = 0;
    set->word = "Get Good";
    set->next = NULL;
    for(int i = 0; i < n; i++)
    {
        arr[i] = set; //set all n spots to null
    }

    wordItem* temp;
    int i;
    for (i=0;i<hashTableSize; i++) //traverse through hash
    {
        temp = hashTable[i];
        while (temp != NULL) //traverse horz
        {
            for (int j = 0; j<n; j++) //check the arr
            {
                if(arr[j] == NULL)
                {
                    arr[j] = temp;
                }

                else if(arr[j]->count<=temp->count && arr[j+1]->count<=temp->count) //see if count is greater than any value in arr
                {    
                    //move items down the array and delete last item 
                    
                }
            }
        
            temp = temp->next;
        }
    }

    for (int k = 0; k < n; k++)
        cout << arr[n]->count << " - " << arr[n]->word << endl;
}