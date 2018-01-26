#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* parent; //new code
};


Node* addNode(Node* tree, int value);
int getSize(Node* tree);
int getMinValue(Node* tree);
int getMaxDepth(Node* tree);
Node* makeNewNode(int val);
Node* deleteNode(Node* node, int val);
Node* search(Node* node, int val);
int getMaxValue(Node* node);


int main(int argc, char* argv[])
{
	Node* root = NULL;
	root = makeNewNode(15);
	root = addNode(root,3);
	root = addNode(root, 20);
	root = addNode(root, 9);
	root = addNode(root, 17);
	cout << "size of tree: " << getSize(root) << endl;
	cout << "max depth: " << getMaxDepth(root) << endl;
	cout << "min: " << getMinValue(root) << endl;
	cout << "current max: " << getMaxValue(root) << endl;
	root = deleteNode(root, 9);
	
	return 0;
}


Node* makeNewNode(int val) // creates new node
{
	Node* node = new Node;
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
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
			tree->left->parent = tree; //new code
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
			tree->right->parent = tree; //new code

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



Node* deleteNode(Node* node, int val)
{
	Node* target = search(node, val);
	if(target != NULL)
	{
		if(target->left != NULL) //target may have one or two children, at least a left child
		{
			int maxLeft = getMaxValue(target->left);
			Node* maxLeftNode = search(target->left, maxLeft);
			if(maxLeftNode->left != NULL) //maxLeftNode has a child
			{
				maxLeftNode->left->parent = maxLeftNode->parent;
				if(maxLeftNode->parent->data > maxLeftNode->data) //maxLeftNode is a child
				{
					maxLeftNode->parent->left = maxLeftNode->left;
				}
				else
				{
					maxLeftNode->parent->right = maxLeftNode->left;
				}

			}
			else //maxLeftNode has no children
			{
				if(maxLeftNode->parent->data > maxLeftNode->parent->left->data)
				{
					maxLeftNode->parent->left = NULL;
				}
				else
				{
					maxLeftNode->parent->right = NULL;
				}
			}
			delete maxLeftNode;
			target->data = maxLeft;
		}
		else if(target->right != NULL) //target has one right child
		{
			int minRight = getMinValue(target->right);
			Node* minRightNode = search(target->right, val);
			if(minRightNode->right != NULL)
			{
				minRightNode->right->parent = minRightNode->parent;
				if(minRightNode->parent->data > minRightNode->data)
				{
					minRightNode->parent->left = minRightNode->right;
				}
				else
				{
					minRightNode->parent->right = minRightNode->right;
				}
			}
			else
			{
				if(minRightNode->parent->data > minRightNode->data)
				{
					minRightNode->parent->left = NULL;
				}
				else
				{
					minRightNode->parent->right = NULL;
				}
			}
			delete minRightNode;
			target->data = minRight;
		}

		else // target for deleetion has no children
		{
				if(target->parent->data > target->data) //target is left child
				{
					target->parent->left = NULL;
				}
				else //target is a right child
				{
					target->parent->right = NULL;
				}
		}
		delete target;
	}
	else
	{
		cout << "item is not in tree, nothing to delete" << endl;
	}

	return node;
}


Node* search(Node* node, int val) //helper function for deletenode
{
	if(node != NULL)
	{
		if(val < node->data && node->left != NULL)
		{
			return search(node->left, val);
		}
		else if(val > node->data && node->right != NULL)
		{
			return search(node->right, val);
		}
		else if(val == node->data)
		{
			return node;
		}
		else
		{
			cout << "value " << val << "not found" << endl;
		}
	}
	return NULL;
}

int getMaxValue(Node* node) //helper function for deleteNode
{
	if(node != NULL)
	{
		while(node->right != NULL) //while method instead of reccurssion 
		{
			node = node->right;

		}
		return node->data;
	}
	return 0;
}




/*
void Delete(int value)
{
	node = search(value)
	if(node != root)
	{
		if(node.leftChild == NULL and node.rightChild == NULL) //no children
		{
			node.parent.leftChild = NULL
		}
		else if(node.leftChild != NULL and node.rightChild != NULL) //two children
		{
			min = treeMinimum(node.rightChild)
			if (min == node.rightChild)
			{
				node.parent.leftChild = min
			}
			else
			{
				min.parent.leftChild = min.rightChild
				min.parent = node.parent
				min.right.parent = min.parent
				node.parent.leftChild = min
				min.leftChild = node.leftChild
				min.rightChild = node.rightChild
				node.rightChild.parent = min
				node.leftChild.parent = min
			}
		}
		else //one child
		{
			x = node.leftChild
			node.parent.leftChild = x
			x.parent = node.parent
		}
	}
	else
	{
	//repeat cases of 0, 1, or 2 children
	//replacement node is the new root
	//parent of replacement is NULL
	delete node
	}
}
*/