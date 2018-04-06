// Implementation file for Graph data structure:
#include "DiGraph.h"
#include <queue>
#include <stack>

// Load function
void DiGraph::loadGraph(){

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

                                DiGraph::insert_edge(srcEdge - 1, currVertex - 1, weight);


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


// Function to insert directed edges in the graph:
void DiGraph::insert_edge(int src, int dest, double weight){

  adjListNode* temp2 = new adjListNode;
  temp2->dest = src;
  temp2->weight = weight;
  temp2->next = adjListGraph[dest];
  adjListGraph[dest] = temp2;

}


// Function to check for cycles in the Graph:
bool DiGraph::isCyclic(){

  // Create an array of false booleans for the visited and recStack values:
  bool* visited = new bool[nVertices];
  bool* recStack = new bool[nVertices];

  // For each vertex in the Graph run the utility function and check for cycles:
  for (int i=0;i<nVertices;i++){
    if (isCyclicUtil(i, visited, recStack)){
      return true;
    }

  }

  cout<<" No cycle detected"<<endl;
  return false;
}


// Utility function to help determine cycles in the Graph:
bool DiGraph::isCyclicUtil(int vertex, bool visited[], bool recStack[]){

    if (visited[vertex]== false){

      visited[vertex] = true;
      recStack[vertex] = true;

      // Now go through each of the neighbors of the current vertex:
      for (adjListNode* neighbor = adjListGraph[vertex]; neighbor!=NULL; neighbor = neighbor->next){

        if (!visited[neighbor->dest] && isCyclicUtil(neighbor->dest, visited,recStack)){
          return true;
        }
        else if (recStack[neighbor->dest]){
            cout<<" Cycle detected at node #"<<neighbor->dest + 1<<endl;
            return true;
          }

    }


}


  recStack[vertex] = false;
  return false;


}


// Function to topologically sort the vertices in the Graph:
void DiGraph::topoSort(){

  // Create an array of false booleans for the visited and recStack values:
  bool* visited = new bool[nVertices];


  for (int i=0;i<nVertices;i++){
    if (visited[i] ==false)
      topoSortUtil(i, visited);
}

}

// Utility function for Topological sort:
void DiGraph::topoSortUtil(int vertex, bool visited[]){

  visited[vertex] = true;


  // Now go through each of the neighbors of the current vertex:
  for (adjListNode* neighbor = adjListGraph[vertex]; neighbor!=NULL; neighbor = neighbor->next){

    if (!visited[neighbor->dest])
      topoSortUtil(neighbor->dest, visited);

}


cout<<vertex + 1<<" -> ";

}

// Compute in degree of the vertices:
int* DiGraph::computeInDegree(){

  int* inDegree = new int[nVertices];

  for (int i=0;i<nVertices;i++){
    inDegree[i] =0;
  }


  for (int vertex =0; vertex < nVertices; vertex++){

    // Now go through each of the neighbors of the current vertex:
    for (adjListNode* neighbor = adjListGraph[vertex]; neighbor!=NULL; neighbor = neighbor->next){

      inDegree[neighbor->dest]++;

    }

  }

  return inDegree;

}


int* DiGraph::computeOutDegree(){


  int* outDegree = new int[nVertices];

  for (int vertex =0; vertex < nVertices; vertex++){


    // Now go through each of the neighbors of the current vertex:
    for (adjListNode* neighbor = adjListGraph[vertex]; neighbor!=NULL; neighbor = neighbor->next){

      outDegree[vertex]++;

    }


  }

  cout<<" Check func 2:"<<outDegree[1]<<endl;

  return outDegree;

}

// Topological sort using Kahn's algorithm:
void DiGraph::topoSortKahn(){

    // Initialize the count of visited nodes to zero:
    int visited = 0;

    //vector<int> topoOrder;
    stack<int> topoOrder;

    // Initialize the out-Degree count:

    // Compute the outDegree of all the nodes:
    int* inDegree = computeInDegree();

    queue<int> currList;

    // Loop through all vertices and add the ones with OutDegree zero to the queue:
    for (int vertex = 0; vertex< nVertices; vertex ++){
      if (inDegree[vertex] == 0){
        currList.push(vertex);
      }
    }

    while (!currList.empty()){

      // Get the vertex at the front of the queue:
      int currVertex = currList.front();
      currList.pop();
      topoOrder.push(currVertex);



      // Iterate over the neighbors of the current vertex:
      for (adjListNode* neighbor = adjListGraph[currVertex]; neighbor!=NULL; neighbor = neighbor->next){

        if (--inDegree[neighbor->dest] == 0){
          currList.push(neighbor->dest);
        }
      }

      visited++;

    }

    // Check if there was a cycle:
    if (visited != nVertices ){
      cout<<" I'm guessing there was a cycle in this graph"<<endl;
      cout<<" Visited is"<<visited<<endl;

    }

    else {
    // Print the vertices in Topological order:
    cout<<" Topological Order for this graph using Kahn's algorithm is"<<endl;


    // for (vector<int>::iterator it_ = topoOrder.begin(); it_ != topoOrder.end();it_ ++){
    //   cout<<*it_ + 1<< "->";
    // }

    while (!topoOrder.empty()){
      cout<<topoOrder.top() + 1<< "->";
      topoOrder.pop();
    }

    }

}

// Get number fo vertices:
int DiGraph::getNumVertices(){
  return nVertices;
}
