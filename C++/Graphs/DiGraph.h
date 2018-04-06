// C++ implementation of a Graph Data structure:
// Two implementations: 1) Adjacency Matrix 2) Adjacency List
// Only doing adjacency list for now:

#ifndef _DIGRAPH_H
#define _DIGRAPH_H


#include <iostream>
#include <string>
#include "Graph.h"
#include <boost/algorithm/string.hpp>



//Each adjacency list is represented bu a pointer to the head node:

// The graph is represented as a dynamic array of adjacency lists:
class DiGraph : public Graph{


public:


// Get the number of vertices:
void loadGraph();

// Override this function;
// Insert an directed edge between two vertices:From src to dest:  New edges are inserted at the head of each adjacency list by convention:
void insert_edge(int src, int dest, double weight);

// Function to detect a cycle in the graph: Start from every vertex, perform DFS and check for cycles:
bool isCyclic();

// Utility function to help detect a cycle in the graph:
bool isCyclicUtil(int vertex, bool visited[], bool recStack []);

// Function to topologically sort the vertices in the Graph:
void topoSort();

// Utility function to topologically sort the vertices:
void topoSortUtil(int vertex, bool visited[]);

// Compute in degree of the vertices:
int* computeInDegree();


// Compute out-degree of all the vertices:
int* computeOutDegree();

// Topological sort using Kahn's algorithm:
void topoSortKahn();


// Get number fo vertices:
int getNumVertices();

// Print the Graph structure:
// void printGraph();
//
// // Print Breadth first traversal order of the Graph given the start vertex:
// void BFS(int startVertex);
//
// // Print Depth first traversal order of the Graph given the start vertex:
// void DFS(int startVertex);
//
// // Recursive sub-function for DFS:
// void DFS_sub(int vertex, bool visited[]);


};

#endif
