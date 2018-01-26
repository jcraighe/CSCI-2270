#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "HW5_BinaryTree.hpp"

using namespace std;

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "MovieTree.hpp"

using namespace std;

MovieTree::MovieTree()
{
    root = NULL;
}

void deleteAll(MovieNode* node)
{
    if(node->leftChild != NULL)
    {
        deleteAll(node->leftChild);
    }
    if(node->rightChild != NULL)
    {
        deleteAll(node->rightChild);
    }
    delete node;
    node = NULL;
    
}

MovieTree::~MovieTree()
{
    deleteAll(root);
}

MovieNode* MovieTree::search(MovieNode *node, std::string title)
{
    MovieNode * Fnode = node;

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

    if(Rnode->quantity == 0)
    {
        cout << "Movie not found." << endl;
        //deleteMovie(title);
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
            delete target;
            target = NULL;
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
            delete target;
            target = NULL;
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
            delete target;
            target = NULL;
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
            delete target;
            target = NULL;
        }
     }
     else
     {
        cout<<"Movie not found."<<endl;
     }
}

void countMoviesN(MovieNode* node, int* c)
{
   if(node->leftChild != NULL)
    {
        countMoviesN(node->leftChild, c);
    }

    (*c)++; //increments the variable at node c not the actual pointer
    
    if(node->rightChild != NULL)
    {
        countMoviesN(node->rightChild, c);
    }
}

void MovieTree::countMovies()
{
    // Your code here
     int count = 0;
     if(root == NULL)
     {
         cout << "Count = " << count << endl;
     }
     else
     {
        countMoviesN(root, &count);
         cout << "Count = " << count << endl;
     }

}