#include <iostream>
#include <climits>
using namespace std;

void bellmanFord(int V, int E, int graph[][3], int source)
{
  // Step 1: Initialize the distance array
  int dist[V];
  for (int i = 0; i < V; i++)
  {
    dist[i] = INT_MAX;
  }
  dist[source] = 0; // Distance to the source is 0

  // Step 2: Relax all edges V-1 times
  for (int i = 1; i <= V - 1; i++)
  {
    for (int j = 0; j < E; j++)
    {
      int u = graph[j][0];      // source vertex of the edge
      int v = graph[j][1];      // destination vertex of the edge
      int weight = graph[j][2]; // weight of the edge

      // Ensure that the source and destination vertices are within bounds
      if (u >= 0 && u < V && v >= 0 && v < V)
      {
        // Relax the edge (u, v)
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
          dist[v] = dist[u] + weight;
        }
      }
    }
  }

  // Step 3: Check for negative-weight cycles
  for (int i = 0; i < E; i++)
  {
    int u = graph[i][0];
    int v = graph[i][1];
    int weight = graph[i][2];
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
    {
      cout << "Graph contains negative weight cycle\n";
      return;
    }
  }

  // Step 4: Print the shortest distances
  cout << "Shortest distances from source " << source << ":\n";
  for (int i = 0; i < V; i++)
  {
    if (dist[i] == INT_MAX)
    {
      cout << "INF ";
    }
    else
    {
      cout << dist[i] << " ";
    }
  }
  cout << endl;
}

int main()
{
  int V = 5; // Number of vertices
  int E = 8; // Number of edges

  // Edge representation as a 2D array: [source, destination, weight]
  int graph[8][3] = {
      {0, 1, -1},
      {0, 2, 4},
      {1, 2, 3},
      {1, 3, 2},
      {1, 4, 2},
      {3, 2, 5},
      {3, 1, 1},
      {4, 3, -3}};

  int source = 0; // Source vertex

  // Run Bellman-Ford algorithm
  bellmanFord(V, E, graph, source);

  return 0;
}
