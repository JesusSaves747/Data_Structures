// Implementation file for Graph data structure:
#include "Graph.h"

// Constructor:
Graph::Graph(){

}


void Graph::loadGraph(){

      string nVerticesStr;

        cout<<" Enter the total number of vertices"<<endl;
        getline(cin,nVerticesStr);
        nVertices = stoi(nVerticesStr);
        adjListGraph = vector<adjListNode*>(nVertices);

        // Get the user input here:
        // Ask the user for values to enter:
        cout<<" Inserting the vertices and edges of a graph"<<endl;
        cout<<" Please enter the edges of the corresponding vertices. Press 'q' to quit"<<endl;

        string userInput;
        string delim_1 = ":";
        string delim_2 = ",";

        bool stopLoop = false;

        int currVertex =1;

        while (!stopLoop && currVertex <= nVertices) {

                cout<<" Please enter the edges of vertex # "<<currVertex<<endl;
                vector<string> edges;

                getline(cin,userInput);

                try {

                        split5(userInput, edges, delim_1);

                        for (vector<string>::iterator _it = edges.begin(); _it!= edges.end(); _it++) {
                                vector<string> edge_weight;
                                split5(*_it, edge_weight, delim_2);

                                int srcEdge = stoi(edge_weight[0]);
                                int weight = stoi(edge_weight[1]);

                                insert_edge(srcEdge - 1, currVertex - 1, weight);


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

                currVertex++;

        }

}



// Insert an  undirected edge between two vertices: New edges are inserted at the head of each adjacency list by convention:
void Graph::insert_edge(int src, int dest, double weight){

        // adjListNode* temp = new adjListNode;
        // temp->dest = dest;
        // temp->weight = weight;
        // temp->next = adjListGraph[src];
        // adjListGraph[src] = temp;

        adjListNode* temp2 = new adjListNode;
        temp2->dest = src;
        temp2->weight = weight;
        temp2->next = adjListGraph[dest];
        adjListGraph[dest] = temp2;




}

// Insert a new vertex in the graph:

// Print the Graph structure:
void Graph::printGraph(){

        cout<<endl<<endl;
        cout<<" The adjacency list representation for the undirected graph is"<<endl;

        for (int i=0; i<nVertices; i++) {

                for (adjListNode* cursor = adjListGraph[i]; cursor!=NULL; cursor= cursor->next) {
                        cout<<cursor->dest + 1 <<"("<<cursor->weight<< ")  , ";
                }

                cout<<endl;
        }


}


// Print Breadth first traversal order of the Graph given the start vertex:
void Graph::BFS(int startVertex){

        // Create an array of booleans to represent whether the node was visited:
        vector<bool> visited(nVertices, false);

        // Create a list which will store a queue of the nodes to be visited:
        list<int> queue;

        queue.push_back(startVertex - 1);

        visited[startVertex - 1] =true;

        cout<<" Breadth first traversal is"<<endl;

        while (!queue.empty()) {

                // Set the current vertex as the first element of the queue:
                int s = queue.front();
                    cout<< s + 1<< "-> ";
                queue.pop_front();

                // Add the neighbors of the current vertex to the queue:
                for (adjListNode* neighbor = adjListGraph[s]; neighbor!=NULL; neighbor = neighbor->next) {

                        if (!visited[neighbor->dest]) {
                                visited[neighbor->dest] = true;
                                queue.push_back(neighbor->dest);
                        }

                }

        }

}

// Recursive sub-function for Depth first search:
void Graph::DFS_sub(int vertex, bool visited[]){

  // Mark the current vertex as visted:
  visited[vertex] = true;

  // Print the vertex:
  cout<<vertex + 1<<"->";

  // Get the neighbors of the current vertex:
  for (adjListNode* neighbor = adjListGraph[vertex]; neighbor!=NULL; neighbor = neighbor->next){

    if (!visited[neighbor->dest]){
      DFS_sub(neighbor->dest , visited);
    }

  }

}

// Print Depth first traversal order of the Graph given the start vertex:
void Graph::DFS(int startVertex){

  // Create a boolean array to indicated whether the node was visited:
  bool *visited = new bool[nVertices];

  cout<<endl;
  cout<<" Depth first Traversal is"<<endl;
  // Call the sub-routine:
  DFS_sub(startVertex -1, visited);

}

// Utility function to find the subset in which a vertex lies: Recursive function:
int Graph::find(int root[], int vertex){

  if (root[vertex] == -1)
    return vertex;

  return find(root, root[vertex]);

}


// Utility function to find the subset in which a vertex lies: Recursive function that uses path compression: Makes time complexity O (Log n) in worst case:
int Graph::find(subset nodes[], int vertex){

  // Assumes that all nodes have parent initialized to -1:
  if (nodes[vertex].parent != vertex){
    nodes[vertex].parent = find(nodes, nodes[vertex].parent);
  }

  return nodes[vertex].parent;

}


// Utility function to form a union of two subsets using the array representation in GFG:
void Graph::join(int root[], int x ,int y){

  int x_sub = find(root, x);
  int y_sub = find(root,y);
  root[x_sub] = y_sub;

}


// Utility function to form a joining of two subsets : Joining by rank
void Graph::join(subset nodes[], int x ,int y){

  // Find the parents of the two vertices:
  int x_root = find(nodes, x);
  int y_root = find(nodes, y);

  // Check the rank of the two roots:
  // If rank of x is smaller than y:Then attach x below y:
  if (nodes[x_root].rank < nodes[y_root].rank){

    nodes[x_root].parent = y_root;
  }
  else if (nodes[x_root].rank > nodes[y_root].rank){
    nodes[y_root].parent = x_root;
  }
  // If the roots are equal: Attach in any order but increment the rank of the parent by 1:
  else{
    nodes[x_root].parent = y_root;
    nodes[y_root].rank++;
  }

}


// Function to check whether a cycle exists in the undirected graph:
bool Graph::isCyclic(vector<edge*>& edgeList){

  // Initialize an array of integers to -1 in order to keep track of the subsets:
  int* root = new int[nVertices];

  for (int i=0;i<nVertices;i++){
    root[i]=-1;
  }

  // Process each edge and check whether the vertices of the edge belong to the same subset:
  for (vector<edge*>::iterator it_ = edgeList.begin() ; it_ != edgeList.end(); it_++){

    // Get the subsets of the two vertices:
    int x_sub = find(root, (*it_)->src);
    int y_sub = find(root, (*it_)->dest);



    if (x_sub == y_sub){

      cout<<" Cycle found at : "<<y_sub<<endl;
      return  true;
    }

    join(root, x_sub, y_sub);

  }

  return false;

}

// Check if the undirected graph contains a cycle: Using rank and Path compression:
bool Graph::isCyclicPCR(vector<edge*>& edgeList){

  // Initialize an array of integers to -1 in order to keep track of the subsets:
  subset* nodes = new subset[nVertices];

  for (int i=0;i<nVertices;i++){
    nodes[i].parent=i;
    nodes[i].rank =0;
  }


  // Process each edge and check whether the vertices of the edge belong to the same subset:
  for (vector<edge*>::iterator it_ = edgeList.begin() ; it_ != edgeList.end(); it_++){

    // Get the subsets of the two vertices:
    int x_sub = find(nodes, (*it_)->src);
    int y_sub = find(nodes, (*it_)->dest);

    cout<<"Edge processed"<<endl;

    if (x_sub == y_sub){

      cout<<" Cycle found at : "<<y_sub<<endl;
      return  true;
  }

  join(nodes, x_sub, y_sub);

}

  return false;

}

// Kruskal's Algorithm to find the Minimum Spanning Tree: Prints the adjacency list representation of the MST
void Graph::MST_Kruskal(){

  vector<edge*> edgeList;


  // Store all the edges in a vector of edge structures:
  for (int vertex = 0; vertex <nVertices; vertex ++){

    for (adjListNode* neighbor = adjListGraph[vertex]; neighbor !=NULL ; neighbor = neighbor->next){

      // Create edge structure:
      edge* currEdge = new edge;
      currEdge->src = vertex;
      currEdge->dest = neighbor->dest;
      currEdge->weight = neighbor->weight;

      // Add the edge to a Min- heap:
      edgeList.push_back(currEdge);


    }
  }

  // Sort the edges using the in-built C++ sort algorithm:
  //sort(edgeList.begin(), edgeList.end(), sortFunc);

  // Now iterate over the sorted list and add edges one by one to the MST:
  //Graph* MST = new Graph(this->getNumVertices());

  // Check if the added edge forms a cycle:


}
