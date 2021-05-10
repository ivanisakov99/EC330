#include <iostream>
#include "Graph.h"

int main(int argc, const char * argv[]) {
    
    // test case 0: just print out graph
    cout << "---------------TEST 0-------------" << endl;
    Graph graph0;
    graph0.generateGraph("graph0.txt");
    graph0.print();

    cout << "\n\n---------------TEST 1-------------" << endl;
    Graph graph1;
    // for part (a)
    graph1.generateGraph("graph0.txt");
    // graph.print();

    // for part (b)
    graph1.modifiedDijkstra(0);

    cout << "\n\n---------------TEST 2-------------" << endl;
    Graph graph2;
    // for part (a)
    graph2.generateGraph("graph1.txt");
    graph2.print();

    // for part (b)
    graph2.modifiedDijkstra(0);

    cout << "\n\n---------------TEST 3-------------" << endl;
    Graph graph3;
    // for part (a)
    graph3.generateGraph("graph1.txt");
    graph3.print();

    // for part (b)
    graph3.modifiedDijkstra(1);

    cout << "\n\n---------------TEST 4-------------" << endl;
    Graph graph4;
    // for part (a)
    graph4.generateGraph("graph2.txt");
    graph4.print();

    // for part (b)
    graph4.modifiedDijkstra(0);

    return 0;
}