#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};


Node* addNode(Node* tree, int value);
int getSize(Node* tree);
int getMinValue(Node* tree);
int getMaxDepth(Node* tree);
Node* makeNewNode(int val);


int main(int argc, char* argv[])
{
	Node* root = NULL;
	root = makeNewNode(8);
	cout << "size of tree: " << getSize(root) << endl;
	cout << "max depth: " << getMaxDepth(root) << endl;
	cout << "current min of tree: " << getMinValue(root) << endl;
	root = addNode(root, 7);
	cout << "size of tree: " << getSize(root) << endl;
	cout << "max depth: " << getMaxDepth(root) << endl;
	cout << "current min of tree: " << getMinValue(root) << endl;
	root = addNode(root, 4);
	cout << "size of tree: " << getSize(root) << endl;
	cout << "max depth: " << getMaxDepth(root) << endl;
	cout << "current min of tree: " << getMinValue(root) << endl;


	
	return 0;
}


Node* makeNewNode(int val) // creates new node
{
	Node* node = new Node;
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node* addNode(Node* tree, int val) //Insert the new value into the BST in the correct position.
{
	if(tree == NULL)
	{
		Node* newNode = makeNewNode(val);
		return newNode;
	}
	else if(val < tree->data)
	{
		if(tree->left != NULL)
		{
			addNode(tree->left, val);
		}
		else
		{
			tree->left = makeNewNode(val);
		}
	}
	else if(val > tree->data)
	{
		if(tree->right != NULL)
		{
			addNode(tree->right, val);
		}
		else
		{
			tree->right = makeNewNode(val);
		}
	}
	else
	{
		cout << "node with value " << val << " already in tree?!" << endl;
	} 

	return tree;
}


int getSize(Node* tree) //Return the total number of nodes in the BST.
{
	int size = 0;
	if(tree != NULL)
	{
		size++;
		size+=getSize(tree->left);
		size+=getSize(tree->right);
	}
	else
	{
		return size;
	}

}


int getMinValue(Node* tree) //Return the minimal value in the BST.
{
	if(tree->left != NULL)
	{
		return getMinValue(tree->left);
	}
	else
	{
		return tree->data;
	}

}


int getMaxDepth(Node* tree) //Return the maximum depth of a path in the tree.
{
	int leftDepth = 1; //equal to 1 to accomidate for last node in tree left
	int rightDepth = 1; //equal to 1 to accomidate for last node in tree right
	if(tree == NULL)
	{
		return 0;
	}
	else
	{
		leftDepth = getMaxDepth(tree->left);
		rightDepth = getMaxDepth(tree->right);
		if(leftDepth > rightDepth)
		{
			return leftDepth;
		}
		else
		{
			return rightDepth;
		}
	}

}
