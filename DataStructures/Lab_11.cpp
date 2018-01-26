#include <iostream>
#include "Graph.hpp"

using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{

}

vertex* Graph::findVertex(std::string vertName)
{
	for(auto i = vertices.begin(); i!= vertices.end(); i++)
	{
		if((*i).name == vertName)
		{
			return &*i; //reference to pointer
		}
	}
	return NULL;
}

void Graph::addVertex(std::string vertName)
{
	vertex v;
	v.name = vertName;
	v.visited = false;
	vertices.push_back(v);
}

void Graph::addEdge(std::string vertA, std::string vertB, int edgeDist) //Directed and weighted 
{
	vertex* vA = findVertex(vertA); //check to see if not NULL
	adjVertex edge;
	edge.distance = edgeDist;
	edge.v = findVertex(vertB);
	vA->adj.push_back(edge);
}

void Graph::BFTraversalLabel(string vertName)
{
	std::vector<vertex*> vertQ;
	vertex *vp = findVertex(vertName);
	for(auto i = vp->adj.begin(); i!= vp->adj.end(); i++) //add more for hw
	{
		if(!(*i).v->visited)
		{
			(*i).v->visited = true;
			vertQ.push_back((*i).v);
			cout << "just visited " << (*i).v->name << endl; //check where you visited
		}
	}

	for(auto qVerts = vertQ.begin(); qVerts != vertQ.end(); qVerts++)
	{
		BFTraversalLabel((*qVerts)->name);
	}
}

int main()
{
	Graph testGraph;
	testGraph.addVertex("vert1");
	testGraph.addVertex("vert2");
	testGraph.addVertex("vert3");
	testGraph.addVertex("vert4");
	testGraph.addVertex("vert5");
	testGraph.addVertex("vert6");
	testGraph.addVertex("vert7");
	testGraph.addVertex("vert8");
	
	testGraph.addEdge("vert1", "vert2", 15);
	testGraph.addEdge("vert1", "vert3", 45);
	testGraph.addEdge("vert3", "vert4", 95);
	testGraph.addEdge("vert2", "vert5", 5);
	testGraph.addEdge("vert5", "vert6", 15);
	testGraph.addEdge("vert5", "vert7", 15);
	testGraph.addEdge("vert5", "vert8", 15);

	testGraph.BFTraversalLabel("vert1");

	return 0;
}