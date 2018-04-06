// Header files:
#include "Graph.h"
#include "DiGraph.h"


int main(int argc, char const *argv[]) {

  Graph* myGraph = new Graph();

  myGraph->loadGraph();

  myGraph->printGraph();

  vector<edge*> edgeList;

    vector<adjListNode*> adjListGraph = myGraph->getAdjList();

  // Store all the edges in a vector of edge structures:
  for (int vertex = 0; vertex <myGraph->getNumVertices(); vertex ++){

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


  if (myGraph->isCyclicPCR(edgeList)){

    cout<<" Oops! Cycle detected in this Graph"<<endl;
  }
  else{
    cout<<" No cycle found in this graph!"<<endl;
  }

  //DiGraph* dg = new DiGraph();

  //dg->loadGraph();

  //dg->printGraph();

  //
  // cout<<" Attempting Topological sort"<<endl;
  //
  // if (!dg->isCyclic()){
  //   dg->topoSort();
  // }
  //
  // else {
  //   cout<<" Graph contains a cycle. Topological sort FAILED!!!"<<endl;
  // }

  // Compute in-degree:
  //int* inDegree = new int[dg->getNumVertices()];

  // int* newCheck = new int[5];
  //
  // cout<<"New out check"<<newCheck[0]<<endl;



  //cout<<" Out check"<<inDegree[0]<<endl;

  //cout<<" Num of vertices is"<<dg->getNumVertices()<<endl;


  // dg->computeOutDegree(inDegree);
  //
  // for (int i=0;i<dg->getNumVertices();i++){
  //   cout<<inDegree[i]<<"->";
  // }
  //
  // cout<<endl;
  //
  //dg->topoSortKahn();

  return 0;
}



// g++ -Wall -std=c++11 -o test_graph driver_program.cpp Graph.cpp DiGraph.cpp
