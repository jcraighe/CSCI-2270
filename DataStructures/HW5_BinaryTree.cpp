#include <iostream>
#include <fstream>
#include <sstream>
#include "HW5_BinaryTree.hpp"

using namespace std;

MovieTree::MovieTree()
{
	root = NULL;
}

void MovieTree::deleteAll(MovieNode * node)
{
    if(node->leftChild != NULL)
    {
        deleteAll(node->leftChild);
    }
    if(node->rightChild != NULL)
    {
        deleteAll(node->rightChild);
    }
    cout<<"Deleting: "<<node->title<<endl;
    delete node;
    node = NULL;
}

MovieTree::~MovieTree()
{
	deleteAll(root);
}

MovieNode* MovieTree::search(MovieNode *node, std::string title)
{
	MovieNode * Fnode = new MovieNode;
    Fnode = node;

    while(Fnode != NULL)
    {
        if(title.compare(Fnode->title) < 0)
        {
            Fnode = Fnode->leftChild;
        }
        else if(title.compare(Fnode->title) > 0)
        {
            Fnode = Fnode->rightChild;
        }
        else if(title.compare(Fnode->title) == 0)
        {
            break;
        }
    }

    return Fnode;
    delete Fnode;
    Fnode = NULL;
}

void MovieTree::printMovieInventory()
{
	if(root == NULL)
    {
        return;
    }
    else
    {
		MovieNode* node = root;
   		if (node->leftChild != NULL)
    	{
    		root = root->leftChild;
        	printMovieInventory();
    	}
    	root = node;
    	cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;

    	if (node->rightChild != NULL)
    	{
    		root = root->rightChild;
    	    printMovieInventory();
    	}
    	root = node;
        delete node;
        node = NULL;
    }
}

void MovieTree::addMovieNode(int ranking, std::string title, int year, int quantity)
{
	MovieNode *innode = new MovieNode(ranking, title, year, quantity);
    innode->parent = NULL;
    innode->leftChild = NULL;
    innode->rightChild = NULL;
    if(root == NULL)
    {
        root = innode;
    }
    else
    {
        MovieNode *temp = root;
        while(temp != NULL)
        {
            if(title.compare(temp->title) < 0)
            {
                if(temp->leftChild != NULL)
                {
                    temp = temp->leftChild;
                }
                else
                {
                    temp->leftChild = innode;
                    innode->parent = temp;
                    temp = NULL;
                }
            }
            else
            {
                if(temp->rightChild != NULL)
                {
                    temp = temp->rightChild;
                }
                else
                {
                    temp->rightChild = innode;
                    innode->parent = temp;
                    temp = NULL;
                }
            }
        }
    }
    delete innode;
    innode = NULL;
}

void MovieTree::findMovie(std::string title)
{
	MovieNode *Fnode = search(root, title);

    if(Fnode == NULL)
    {
        cout<<"Movie not found."<<endl;
        return;
    }

    cout << "Movie Info:" << endl;
    cout << "===========" << endl;
    cout << "Ranking:" << Fnode->ranking << endl;
    cout << "Title:" << Fnode->title << endl;
    cout << "Year:" << Fnode->year << endl;
    cout << "Quantity:" << Fnode->quantity << endl;
}

void MovieTree::rentMovie(std::string title)
{
	MovieNode *Rnode = search(root, title);

    if(Rnode == NULL)
    {
        cout<<"Movie not found."<<endl;
        return;
    }

    if(Rnode->quantity <= 0)
    {
        cout << "Movie out of stock." << endl;
        return;
    }

    Rnode->quantity = Rnode->quantity - 1;

    cout << "Movie has been rented." << endl;
    cout << "Movie Info:" << endl;
    cout << "===========" << endl;
    cout << "Ranking:" << Rnode->ranking << endl;
    cout << "Title:" << Rnode->title << endl;
    cout << "Year:" << Rnode->year << endl;
    cout << "Quantity:" << Rnode->quantity << endl;


    if(Rnode->quantity == 0)
    {
        deleteMovie(title);
    }
}

void MovieTree::deleteMovie(std::string title)
{
    MovieNode* target = search(root, title);

    if(target != NULL)
    {
        if(target->leftChild == NULL && target->rightChild == NULL) // target has no children 
        {
            if(target == root)
            {
                root = NULL;
            }
            else
            {
                target = NULL;
            }
        }
        else if(target->leftChild != NULL && target->rightChild == NULL) //target with left child
        {
            if(target == root)
            {
                root = target->leftChild;
            }
            else
            {
                target->leftChild->parent = target->parent;
                target->parent->leftChild = target->leftChild;
            }  
        }
        else if(target->leftChild == NULL && target->rightChild != NULL) //target with right child
        {
            if(target == root)
            {
                root = target->rightChild;
            }
            else
            {
                target->rightChild->parent = target->parent;
                target->parent->rightChild = target->rightChild;
            }  
        }
        else if(target->leftChild != NULL && target->rightChild != NULL) //target with two children  replace with left
        {
            if(target == root)
            {
                root = target->leftChild;
                root->rightChild = target->rightChild;
            }
            else
            {
                target->leftChild->parent = target->parent;
                target->parent->leftChild = target->leftChild;
            }  
        }
     }
     else
     {
        cout<<"Movie not found."<<endl;

     }

     delete target;
     target = NULL;
}

void MovieTree::countMovies(MovieNode* node, int* c)
{
   if(node->leftChild != NULL)
    {
        countMovies(node->leftChild, c);
    }

    (*c)++; //increments the variable at node c not the actual pointer

    if(node->rightChild != NULL)
    {
        countMovies(node->rightChild, c);
    }
}

void MovieTree::countMovies()
{
    int count = 0;
    if(root == NULL)
    {
        cout << "Count = " << count << endl;
    }
    else
    {
        countMovies(root, &count);
        cout << "Count = " << count << endl;
    }
}



