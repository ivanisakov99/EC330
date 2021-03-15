#include <stdio.h>

#include <limits.h>

#define V 5
int minDistance(int dist[], bool sptSet[])
{
// Initialize min value
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
   if (sptSet[v] == false && dist[v] <= min)
       min = dist[v], min_index = v;

return min_index;
}

int printSolution(int dist[], int n)
{
printf("Vertex Distance from Source\n");
for (int i = 0; i < V; i++)
   printf("%d \t\t %d\n", i, dist[i]);
}


void dijkstra(int graph[V][V], int src)
{
   int dist[V];   // The output array. dist[i] will hold the shortest
                   // distance from src to i

   bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                   // path tree or shortest distance from src to i is finalized

  
   for (int i = 0; i < V; i++)
       dist[i] = INT_MAX, sptSet[i] = false;

   dist[src] = 0;

   for (int count = 0; count < V-1; count++)
   {
  
   int u = minDistance(dist, sptSet);

  
   sptSet[u] = true;

   for (int v = 0; v < V; v++)

       if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                   && dist[u]+graph[u][v] < dist[v])
           dist[v] = dist[u] + graph[u][v];
   }

   // print the constructed distance array
   printSolution(dist, V);
}

// driver program to test above function
int main()
{

int graph[V][V] = {{1, 1, 0, 0, 1},
                   {0, 1, 0, 1, 1},
                   {0, 1, 1, 0, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 0, 1, 1},
                   };

   dijkstra(graph, 0);

   return 0;
}