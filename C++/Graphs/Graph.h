// C++ implementation of a Graph Data structure:
// Two implementations: 1) Adjacency Matrix 2) Adjacency List
// Only doing adjacency list for now:
#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace std;

// Function to split the user string input:
template <class Container>
void split5(const std::string& str, Container& cont,
            const std::string& delims = " ")
{
        boost::split(cont, str, boost::is_any_of(delims));
}

// Step 1: Create a structure for an adjacency list node:
struct adjListNode {

        int dest;
        double weight;
        adjListNode* next;

};

// Step 2: Create a structure to store edges:
struct edge{

  int src;
  int dest;
  int weight;
};

// Step 3: Create a structure to store the subsets of nodes in an undirected graph for use the Rank join and Path compression algorithm:
struct subset{
  int parent;
  int rank;
};

// // Function for sorting the edges:
// bool sortFunc(const edge* i, const edge* j){
//
//   return ( i->weight < j-> weight);
// }

//Each adjacency list is represented bu a pointer to the head node:

// The graph is represented as a dynamic array of adjacency lists:
class Graph {

protected:
int nVertices;
vector<adjListNode*> adjListGraph;

public:
// Constructor:
Graph();

// Parameterized constructor: Used to Initialize a Minimum Spanning Tree:
Graph(int nVertices){
  adjListGraph = vector<adjListNode*>(nVertices);
}

// Get number fo vertices:
int getNumVertices(){
  return nVertices;
}

// Get the adjacency lists:
vector<adjListNode*> getAdjList(){
  return adjListGraph;
}

// Get the graph Data from user:
void loadGraph();

// Insert an  undirected edge between two vertices: New edges are inserted at the head of each adjacency list by convention:
void insert_edge(int src, int dest, double weight);

// Insert a new vertex in the graph:

// Print the Graph structure:
void printGraph();

// Print Breadth first traversal order of the Graph given the start vertex:
void BFS(int startVertex);

// Print Depth first traversal order of the Graph given the start vertex:
void DFS(int startVertex);

// Recursive sub-function for DFS:
void DFS_sub(int vertex, bool visited[]);

// Check if the undirected graph contains a cycle:
bool isCyclic(vector<edge*>& edgeList);

// Check if the undirected graph contains a cycle: Using rank and Path compression:
bool isCyclicPCR(vector<edge*>& edgeList);


// Utility function to find the subset in which a vertex lies: Recursive function:
int find(int root[], int vertex);

// Utility function to find the subset in which a vertex lies: Recursive function that uses path compression: Makes time complexity O (Log n) in worst case:
int find(subset nodes[], int vertex);



// Utility function to form a union of two subsets using the array representation in GFG: union is a keyword ic C++
void join(int root[], int x ,int y);

// Utility function to form a union of two subsets using the array representation in GFG: union is a keyword ic C++
void join(subset nodes[], int x ,int y);


// // Kruskal's Algorithm to find the Minimum Spanning Tree: Prints the adjacency list representation of the MST
void MST_Kruskal();


};

#endif
