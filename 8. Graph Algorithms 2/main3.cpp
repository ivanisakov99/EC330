//
//  main.cpp
//  Dijkstra
//
//  Created by Tali Moreshet
//

#include <iostream>
#include "Graph.h"

int main(int argc, const char * argv[]) {
    
    // test case 3: test graph1.txt starting at vertex 1
    /*if (argc != 2)
    {
        cout << "Please supply a file name as input" << endl;
        return -1;
    }*/
    
    Graph graph;
    // for part (a)
    graph.generateGraph("graph1.txt");
    graph.print();

    // for part (b)
    graph.modifiedDijkstra(1);
    
    return 0;
}