#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>> &graph, int V)
{
  // Initialize the distance matrix with the graph values
  vector<vector<int>> dist = graph;

  // Loop over all intermediate vertices
  for (int k = 0; k < V; k++)
  {
    // Loop over all source vertices
    for (int i = 0; i < V; i++)
    {
      // Loop over all destination vertices
      for (int j = 0; j < V; j++)
      {
        // If the path through k is shorter, update the distance
        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
        {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  // Print the shortest distance matrix
  cout << "Shortest distances between every pair of vertices:\n";
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (dist[i][j] == INT_MAX)
        cout << "INF ";
      else
        cout << dist[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int V = 4; // Number of vertices in the graph
  vector<vector<int>> graph(V, vector<int>(V, INT_MAX));

  // Initialize the graph with the edge weights (graph[i][j] is the edge weight from i to j)
  // 0 denotes the absence of an edge between i and j
  for (int i = 0; i < V; i++)
  {
    graph[i][i] = 0; // The distance from a node to itself is always 0
  }

  // Example graph initialization (adjacency matrix)
  graph[0][1] = 5;
  graph[0][2] = 10;
  graph[1][2] = 3;
  graph[1][3] = 1;
  graph[2][3] = 2;

  // Run Floyd-Warshall algorithm
  floydWarshall(graph, V);

  return 0;
}
