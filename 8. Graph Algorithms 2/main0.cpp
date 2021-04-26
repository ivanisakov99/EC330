//
//  main.cpp
//  Dijkstra
//
//  Created by Tali Moreshet
//

#include <iostream>
#include "Graph.h"

int main(int argc, const char * argv[]) {
    
    // test case 0: just print out graph
    /*if (argc != 2)
    {
        cout << "Please supply a file name as input" << endl;
        return -1;
    }*/
    
    Graph graph;
    // for part (a)
    graph.generateGraph("graph0.txt");
    graph.print();

    // for part (b)
    //graph.modifiedDijkstra(0);
    
    return 0;
}