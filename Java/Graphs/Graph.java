// Class to represent a Graph using an adjacency list representation:
// Later add some utility functions:
// 1. Breadth first search:
// 2. Depth- first search:
// 3. Print Graph:
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Arrays;
import java.util.List;


// Use an ArrayList of LinkedLists to represent the graph:
public class Graph {

        // Number of vertices in the graph:
        private int nVertices;

        // Now create an ArrayList of empty AdjList head nodes to represent the graph:
        private LinkedList<Integer> adjListGraph[];

        // Constructor for the Main Graph class: Input the number of vertices:
        public Graph(){

                // Create a scanner object to get user input:
                Scanner myScan = new Scanner(System.in);

                System.out.println("\n  Enter the number of vertices in the Graph");

                nVertices = myScan.nextInt();

                adjListGraph = new LinkedList[nVertices]; // Initial number of vertices

                // Create a new list for each vertex
            // such that adjacent nodes can be stored
            for(int i = 0; i < nVertices ; i++){
                adjListGraph[i] = new LinkedList<>();
            }

        }

        // Get the edges for different vertices from the user:
        public void loadGraph(){

          // Create a scanner object to get user input:
          Scanner myScan = new Scanner(System.in);

                System.out.println("\n  Please Enter the edge of vertices in the Graph");

                for (int i =0; i<nVertices; i++) {

                        System.out.println("\n  Enter the edges of vertex #  "+ (i+1) );

                        try{

                                String edgeStr = myScan.next();

                                List<String> edges = Arrays.asList(edgeStr.split(","));

                                for (String it_ : edges){

                                  int dest = Integer.parseInt(it_);
                                  insert_edge(i, dest-1); // Not keeping weight on the edges for now:
                              }
                        }

                        catch (Exception e){
                          System.out.println(e);

                        }

                }


        }

        // Function to insert edges in the graph: Directed graph for now:
        public void insert_edge(int src, int dest){

          adjListGraph[src].addFirst(dest); // Very useful function

        }

        // Print the graph for testing:
        public void printGraph(){

            System.out.println(" The adjacency list representation of the graph is: ");
            
            // Loop over the ArrayList:
            for (int i = 0; i < nVertices;i++){

              for (Integer it_ : adjListGraph[i] ){
              System.out.print( (it_ + 1) + " -> ");
            }

              System.out.println(" ");
            }



        }


}
