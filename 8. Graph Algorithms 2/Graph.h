#ifndef Graph_h
#define Graph_h

#include <set>
#include <map>
#include <string>

using namespace std;

// Directed edge(u, v)
typedef pair<int, int> directedEdge;

// Implements a directed, weighted graph
class Graph {
   public:
      // Constructs a graph with no edges or vertices.
      Graph();
    
      // Adds a vertex to the graph.
      // Returns the ID of the added vertex.
      int addVertex();
    
      // Adds the given edge with the provided weight to the graph.
      // The vertices of <newEdge> must currently exist in the graph.
      void addEdge(directedEdge newEdge, int weight);
    
      // Returns the number of vertices in the graph.
      int getNumVertices();
    
      // Returns the weight of the provided edge. The edge must exist in the graph. 
      int getWeight(directedEdge edge);

      // Returns true iff there is an edge in the graph with the same vertices as newEdge.
      bool isEdge(directedEdge newEdge);
    
      // Prints a human-readable version of the adjacency list of the graph.
      // Format is: vertex: adjacent_vertex_1 (weight_1) adjacent_vertex_2 (weight_2) ...
      void print();
    
      // Constructs a graph from the file with the provided name.
      // The file format is as follows: 
      // The first line contains the number of vertices and the number of edges, separated by a space,
      // followed by optional additional text.
      // The graph is assumed to contain vertices numbered 0 to 'number of vertices' - 1.
      // Each of the remaining lines contain one edge specified by the source and destination vertices 
      // followed by the weight, and separated by spaces. 
      // Returns the constructed graph.
      void generateGraph(string fileName);

      void modifiedDijkstra(int source);
    
   private:
      // The set of vertices of the graph
      set<int> vertices;              
      // The set of edges of the graph
      set<directedEdge> edges;        
      // A mapping between edges and their weights 
      map<directedEdge, int> weights; 
};

#endif /* Graph_h */
