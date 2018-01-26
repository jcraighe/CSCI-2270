/*
	Graph Implementation
	
	Need: node for data as a LinkedList
		  array to hold the edge nodes
		  Graph
*/

#include <iostream>
#include <cstdlib>
using namespace std;


// adjacency list node
struct AdjListNode
{
	int data;
	AdjListNode *next;
};


// adjacency list
struct AdjList
{
	AdjListNode *head;
};


// Graph
struct Graph
{
	int numVerticies;
	AdjList *arr;
};


//function prototypes
Graph *createGraph(int numVerticies);
void addEdge(Graph *grph, int src, int dest);
AdjListNode *newAdjListNode(int data);
void printGraph(Graph *g);


int main()
{
	//  create new graph
	int totalVerticies = 4;
	Graph *graph;
	graph = createGraph(totalVerticies);
	//connect edges
	addEdge(graph,0,1);
	addEdge(graph,0,2);
	addEdge(graph,0,3);
	addEdge(graph,1,3);
	addEdge(graph,2,3);
	printGraph(graph);
	return 0;
}


// Functions
AdjListNode *newAdjListNode(int data)
{
	AdjListNode *nptr = new AdjListNode;
	nptr->data = data;
	nptr->next = NULL;
	return nptr;
}

Graph *createGraph(int _numVerticies)
{
	Graph *graph = new Graph;
	graph->numVerticies = _numVerticies;
	// create an array of adjacency list - size of array = numVert
	graph->arr = new AdjList[_numVerticies];
	for(int i = 0; i < _numVerticies; i++)
	{
		graph->arr[i].head = NULL;
	}
	return graph;
}

void addEdge(Graph *grph, int src, int dest)
{
	// adding an edge from source to destination
	// node added at beginning
	AdjListNode *nptr = newAdjListNode(dest);
	nptr->next = grph->arr[src].head;
	grph->arr[src].head = nptr;
	// if undirected
	nptr = newAdjListNode(src);
	nptr->next = grph->arr[dest].head;
	grph->arr[dest].head = nptr;
}

void printGraph(Graph *g)
{
	// loop over each adj list
	for(int i = 0; i < g->numVerticies; i++)
	{
		AdjListNode *root = g->arr[i].head;
		cout << "adjacencylist of vertex " << i << endl;
		// loop over each node in list
		while(root != NULL)
		{
			cout << root->data;
			if(root->next != NULL)
			{
				cout << " --> ";
			}
			root = root->next;
		}
		cout << endl;
	}
}








