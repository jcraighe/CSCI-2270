#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

struct vertex;

struct adjVertex
{
	vertex *v;
	int distance;
};

struct vertex
{
	int ID;
	std::string name;
	bool visited;
	std::vector<adjVertex> adj;
};

class Graph
{
public:
	Graph();
	~Graph(); //do the same thing ---- nothing
	void addEdge(std::string vert1, std::string vert2, int distance);
	void addVertex(std::string name);
	void BFTraversalLabel(std::string startingVert);

private:
	std::vector<vertex> vertices;
	vertex* findVertex(std::string name);
};

#endif