// will work for -ve weights too
// work for directed graph
// for undirected graph just change it to directed graph by assigning 2 directions ie from suppose 1 to 2 and from 2 to 1.
// n-1 iterations needed here
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bellman(int v, vector<vector<int>> &edges, int s)
{
  vector<int> dist(v, 1e8);
  dist[s] = 0;
  for (int i = 0; i < v - 1; i++)
  {
    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      int wt = it[2];
      if (dist[u] != 1e8 && dist[u] + wt < dist[v])
      {
        dist[v] = dist[u] + wt;
      }
    }
  }
  // code for bellman is completed
  // now checking for if cycle is -ve
  // that we can check on seeing is now also dist is less coming thn before as now if it is so then it must be -ve.

  for (auto it : edges)
  {
    int u = it[0];
    int v = it[1];
    int wt = it[2];
    if (dist[u] != 1e8 && dist[u] + wt < dist[v])
    {
      return {-1};
    }
  }
  return dist;
}

int main()
{
  int v, e;
  cout << "Enter number of vertices and edges: ";
  cin >> v >> e;

  vector<vector<int>> edges;
  cout << "Enter " << e << " edges in format: u v weight" << endl;
  for (int i = 0; i < e; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  int src;
  cout << "Enter source vertex: ";
  cin >> src;

  vector<int> result = bellman(v, edges, src);

  if (result.size() == 1 && result[0] == -1)
  {
    cout << "Negative weight cycle detected!" << endl;
  }
  else
  {
    cout << "Shortest distances from source " << src << ":" << endl;
    for (int i = 0; i < v; i++)
    {
      if (result[i] == 1e8)
        cout << "Node " << i << ": INF" << endl;
      else
        cout << "Node " << i << ": " << result[i] << endl;
    }
  }

  return 0;
}