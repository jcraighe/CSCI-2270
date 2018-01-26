#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include "HW7_Hash.cpp"

using namespace std;

int main()
{
	HashTable* my = new HashTable(10);
	my->addWord("IT");
	my->getTotalNumberNonStopWords();
	return 0;
}