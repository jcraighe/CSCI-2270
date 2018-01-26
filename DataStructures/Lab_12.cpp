#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

//number of verticies in graph
#define V 3 //define a constant c style

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX;
	int min_index;

	for(int v=0; v<V; v++)
	{
		if(sptSet[v] == false && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		} 

	}
	return min_index;
}

void printSolution(int dist[], int n)
{
	cout << "Vertex\t\tDistance from Start" << endl;
	for(int i=0; i<V; i++)
	{
		cout << i << "\t\t\t" << dist[i] << endl;
	}
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; 
	bool sptSet[V]; 

	for(int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	dist[src] = 0;

	for(int count = 0; count < (V-1); count++)
	{
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for(int v=0; v<V; v++)
		{
			if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	printSolution(dist,V);
}



int main()
{
	int graph[V][V] = {{0,4,0}, {4,0,30}, {0,8,8}};

	dijkstra(graph, 0);

	return 0;
}




