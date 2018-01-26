#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include "Graph.hpp"

using namespace std;

/*
class constructor
Purpose: perform all operations necessary to instantiate a class
object
Parameters: none
*/
Graph::Graph()
{

}
/*
class destructor
Purpose: free all resources that the object has aquired
Parameters: none
*/
Graph::~Graph()
{

}
/*
Method Name: findVertex
Purpose: Find and return the vertex of the specified city
Param: name - name of the city vertex to be returned
returns pointer to a vertex
*/
vertex* Graph::findVertex(std::string name)
{
	for(auto i = vertices.begin(); i!= vertices.end(); i++)
	{
		if((*i).name == name)
		{
			return &*i; //reference to pointer
		}
	}
	return NULL;
}
/*
Method Name: BFTraversalLabel
Purpose: Call BFTraversalLabel from within assignDistricts to label
the districts. This method should implement a breadth first
traversal from the startingCity and assign all cities
encountered the distID value
Param: name - name of starting city for breadth first traversal
*/
void Graph::BFTraversalLabel(std::string startingCity, int distID)
{
	std::queue<vertex*> q;
    // Label all as unvisited.
    for(int i = 0; i < int(vertices.size()); i++)
    {
        vertices[i].visited = false;
    }
    // Find the starting node and enqueue it.
    for(int i = 0; i < int(vertices.size()); i++)
    {
        if (vertices[i].name == startingCity)
        {
            // set current vertex to be visited.
            vertices[i].visited = true;
            q.push(&vertices[i]);
            vertices[i].district = distID;
            break;
        }
    }
    // Now do the rest of the search.
    while (q.empty() != true)
    {
        vertex * u = q.front();
        q.pop();
        for(int i = 0; i < int(u->adj.size()); i++)
        {
            if (u->adj[i].v->visited == false)
            {
                u->adj[i].v->visited = true;
                u->adj[i].v->district = distID;
                q.push(u->adj[i].v);
            }
        }
    }
}
/*
Method Name: addEdge
Purpose: Creates an edge between two vertices (using an adjVertex
struct)
Param: v1 - vertex at one end of edge
Param: v2 - vertex at opposite end of edge
*/
void Graph::addEdge(std::string v1, std::string v2, int distance)
{
    vertex* vA = findVertex(v1); //check to see if not NULL
	adjVertex edge;
	edge.distance = distance;
	edge.v = findVertex(v2);
	vA->adj.push_back(edge);
}
/*
Method Name: addVertex
Purpose: Creates a vertex

Param: name - name of the vertex (city name)
*/
void Graph::addVertex(std::string name)
{
    vertex v;
	v.name = name;
	v.visited = false;
	vertices.push_back(v);
}
/*
Method Name: displayEdges
Purpose: print all edges in graph (see writeup for format)
Parameters: none
*/
void Graph::displayEdges()
{
	for(int i = 0; i < int(vertices.size()); i++)
	{
        cout<< vertices[i].district <<":" <<vertices[i].name<<"-->";
        
        for(int j = 0; j < int(vertices[i].adj.size()); j++)
        {
            cout<<vertices[i].adj[j].v->name;
            cout<< " (" << vertices[i].adj[j].distance << " miles)";
            
            if (j != int(vertices[i].adj.size()-1))
            {
                cout<<"***";
            }
        }
        cout << endl;
    }
}
/*
Method Name: assignDistricts
Purpose: Iterate through the vertices, perform BFT to find connected
components, and assign to district
Parameters: none
*/
void Graph::assignDistricts()
{
	// Starting district num
    int distID = 1;
    // For each of the vertices
    for(int i = 0; i < int(vertices.size()); i++)
    {
        // Only consider a vertex that has not been assigned a district.
        if (vertices[i].district <= 0)
        {
            // Run breadth first traversal and assign each node in the network to this district.
            BFTraversalLabel(vertices[i].name,distID);
            distID++;
        }
    }
}



int main(int argc, char* argv[])
{
	ifstream infile;
	infile.open(argv[0]);
	string line;
	stringstream ss;
	stringstream name;

	while(getline(filein,line))
	{

	}
}








