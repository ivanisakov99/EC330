#include <iostream>
#include "Graph.h"
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits.h>
#include <stdio.h>

using namespace std;


//Constructs a graph with no edges or vertices
Graph::Graph(){
    //empty
}

//Adds a vertex to the graph, and returns the ID of the added vertex
int Graph::addVertex(){
    int newVertex = getNumVertices();
    vertices.insert(newVertex);
    
    return newVertex;
}

//Adds the given edge with the provided weight to the graph
void Graph::addEdge(directedEdge newEdge, int weight){
    if( (vertices.find(newEdge.first) != vertices.end()) && (vertices.find(newEdge.second) != vertices.end()) ){
        edges.insert(newEdge);
        weights.insert(pair<directedEdge, int>(newEdge, weight));
    }
    
}

//Returns the number of vertices in the graph
int Graph::getNumVertices(){
    return vertices.size();
}

//Returns the weight of the provided edge
int Graph::getWeight(directedEdge edge){
    map<directedEdge, int>::iterator it;
    it = weights.find(edge);
    return it->second;
}

//Returns true iff there is an edge in the graph with the same vertices as newEdge
bool Graph::isEdge(directedEdge newEdge){
    set<directedEdge>::iterator it;
    it = edges.find(newEdge);

    if(it != edges.end()){
        return true;
    }else{
        return false;
    }
}

//Prints a human-readable version of the adjacency list of the graph.
//Format is: vertex: adjacent_vertex_1 (weight_1) adjacent_vertex_2
//(weight_2) ...
void Graph::print(){
    directedEdge it1;
    map<directedEdge, int>::iterator it3;
    
    for (set<int>::iterator it = vertices.begin(); it != vertices.end(); ++it){
        cout << *it << ": ";
        for (set<directedEdge>::iterator it2 = edges.begin(); it2 != edges.end(); ++it2){
            it1 = *it2;
            it3 = weights.find(it1);
            if(it1.first == *it){
                cout << it1.second << " (" << it3->second << ") ";
            }
            
        }
        cout << "" << endl;
    }
    
}

//Constructs a graph from the file with the provided name. The file format is as follows: The first line contains the number of vertices and the number of edges, 
//separated by a space, followed by optional additional text. The graph is assumed to contain vertices numbered 0 to 'number of vertices' - 1. Each of the remaining 
//lines contain one edge specified by the source and destination vertices followed by the weight, and separated by spaces. Returns the constructed graph.
void Graph::generateGraph(string fileName){
    ifstream input(fileName);
    string line, temp;
    stringstream ss1;
    int integer, numV, numE;
    
    getline(input, line);
    
    ss1 << line;

    ss1 >> temp;
    //Getting the number of vertices
    if(stringstream(temp) >> integer){
        numV = integer;
    }
    temp = "";

    ss1 >> temp;
    //Getting the number of edges
    stringstream(temp) >> integer;
    
    numE = integer;
    
    temp = "";
        
    //intialising a 2D array for the edges and weights
    int **list = new int *[numE];
    for(int i = 0; i < numE; i++){
        list[i] = new int[3];
    }

    int x = 0, y = 0;
    while(getline(input, line)){
        stringstream ss2;
        ss2 << line;
        int edge;

        while(!ss2.eof()){
            ss2 >> temp;
            if(stringstream(temp) >> edge){
                list[x][y] = edge;
            }
            temp = "";
            y++;
        }
        y = 0;
        x++;
    }
    
    //Closing the input file
    input.close();
    
    //Filling the set of vertices
    for (int i = 0; i < numV; i++){
        vertices.insert(i);
    }

    int j = 0;
    //Filling the set of edges and the mapping between the edges and their weights
    for(int i = 0; i < numE; i++){
        directedEdge adj = make_pair(list[i][j], list[i][j + 1]);
        edges.insert(adj);
        weights.insert(pair<directedEdge, int>(adj, list[i][j + 2]));
    } 
    
    //Deleting the 2D array
    for(int i = 0; i < 3; i++){
        delete[] list[i];
    }
    delete[] list;
    
}

//Function to find the minimum distance in the shortest path set
int MinD(int distance[],  bool ShortestPathSet[], int numV) 
{ 
      
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < numV; v++) {
        if (ShortestPathSet[v] == false && distance[v] <= min) {
            min = distance[v]; 
            min_index = v; 
        }
    }
  
    return min_index; 
} 

//Using Dijkstra to print out the distance of the shortest path and the number of shortest paths that exist.
//The modification for this algorithm that I made, was that when I am relaxing, instead of checking if d[v] is just bigger than
//d[u] + weight[u,v]. Check if it is bigger or equal than d[u] + weight[u,v], so that if it is equal to the d[u] + weight[u,v],
//then there is another shortest path
void Graph::modifiedDijkstra(int source){
    int numV = getNumVertices();
    
    //Distance from the source to a particular vertex
    int distance[numV];
    
    //The set of vertices if they are included in the shortest path
    bool ShortestPathSet[numV];

    //The predecessor of the current vertex
    int predecesssor[numV];

    //The length of the shortest path
    int ShortestPath[numV];
    
    //Initialise all distances to INT_MAX and all the elements of the set as false
    for (int i = 0; i < numV; i++) 
    { 
        distance[i] = INT_MAX; 
        ShortestPathSet[i] = false;
        predecesssor[0] = -1; 
        ShortestPath[i] = 0;
    } 

    //Distance from the source is always 0
    distance[source] = 0;

    //Finding the shortest path for all vertices
    for (int count = 0; count < numV; count++) 
    { 
        //Pick the minimum distance from the set
        int u = MinD(distance, ShortestPathSet, numV); 

        //Mark the vertex as visited->true
        ShortestPathSet[u] = true; 
        
        //Updating the values of the distances of the adjacent vertices for a specific vertex
        for (int v = 0; v < numV; v++) {
            directedEdge W = make_pair(u, v);
            

            //Step inside iff the overall weight will be less if this path is chosen
            if (isEdge(W) && distance[u] + getWeight(W) <= distance[v]) 
            { 
                //Step inside iff there is a path to the same vertex which has equal weight
                if(distance[u] + getWeight(W) == distance[v]){
                    if(predecesssor[v] != -1){
                        ShortestPath[v] += 1;
                    }
                    
                }else{
                    predecesssor[v] = u; 
                    distance[v] = distance[u] + getWeight(W); 
                    ShortestPath[v] += 1;
                }
                
                //If the predecessor of a vertex has more than one shortest paths associated with it, carry this information to the next connected vertex
                if(ShortestPath[u] > 1){
                    ShortestPath[v] += 1;
                }
            }  
        }
       
    } 
    
    //Printing the output for the shortest distances to each vertex from the source and the number of shortest paths associated with those distances
    cout << "\nShortest paths from node " << source << ":" << endl;
    for(int i = 0; i < getNumVertices(); i++){
        if(i != source){
            cout << "Distance to vertex " << i << " is " << distance[i] << " and there are " << ShortestPath[i] << " shortest paths" << endl;
        }
    }
}