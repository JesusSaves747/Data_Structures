// C++ implementation of a Graph Data structure:
// Two implementations: 1) Adjacency Matrix 2) Adjacency List
// Only doing adjacency list for now:
#include <iostream>
#include <string>
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


//Each adjacency list is represented bu a pointer to the head node:

// The graph is represented as a dynamic array of adjacency lists:
class Graph {

private:
int nVertices;
vector<adjListNode*> adjListGraph;

public:
// Constructor:
Graph(){

        nVertices = 0;
        adjListGraph.push_back(new adjListNode);

        // Get the user input here:
        // Ask the user for values to enter:
        cout<<" Inserting the vertices and edges of a graph"<<endl;
        cout<<" Please enter the edges of the corresponding vertices. Press 'q' to quit"<<endl;

        string userInput;
        string delim_1 = ":";
        string delim_2 = ",";

        bool stopLoop = false;

        while (!stopLoop) {

                cout<<" Please enter the edges of vertex # "<<++nVertices<<endl;
                adjListGraph.push_back(new adjListNode);
                vector<string> edges;

                getline(cin,userInput);

                try {

                        split5(userInput, edges, delim_1);

                        for (vector<string>::iterator _it = edges.begin(); _it!= edges.end(); _it++) {
                                vector<string> edge_weight;
                                split5(*_it, edge_weight, delim_2);

                                int srcEdge = stoi(edge_weight[0]);
                                int weight = stoi(edge_weight[1]);

                                insert_edge(srcEdge, nVertices, weight);


                        }

                }
                catch (const std::invalid_argument& ia) {


                        if (userInput[0] == 'q' || userInput[0]=='Q') {
                                stopLoop =true;
                        }

                        else{
                                std::cerr << "Invalid argument: " << ia.what() << '\n';
                        }

                }

        }

}

// Get the number of vertices:

// Insert an  undirected edge between two vertices: New edges are inserted at the head of each adjacency list by convention:
void insert_edge(int src, int dest, double weight){

        adjListNode* temp = new adjListNode;
        temp->dest = dest;
        temp->weight = weight;
        temp->next = adjListGraph[src];
        adjListGraph[src] = temp;

        adjListNode* temp2 = new adjListNode;
        temp2->dest = src;
        temp2->weight = weight;
        temp2->next = adjListGraph[dest];
        adjListGraph[dest] = temp2;




}

// Insert a new vertex in the graph:

// Print the Graph structure:
void printGraph(){

  cout<<endl<<endl;
  cout<<" The adjacency list representation for the undirected graph is"<<endl;

        for (int i=0; i<nVertices; i++) {

                for (adjListNode* cursor = adjListGraph[i]; cursor->next!=NULL; cursor= cursor->next) {
                        cout<<cursor->dest<<"("<<cursor->weight<< ")  , ";
                }

                cout<<endl;
        }


}

};


// Driver function to test the code:
int main(int argc, char const *argv[]) {

  Graph* myGraph = new Graph();

  myGraph->printGraph();

  return 0;
}
