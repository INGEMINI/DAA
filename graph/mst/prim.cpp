#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// spanning tree defination
// tree in which we have n nodes and n-1 edges and all nodes are reachable from each other.
// any tree which has minimum sum of spanning tree is known as mst(minimum spanning tree)

// prims algo is used to find mst
// things we need ..visited array..min_heap

// func to find sum of weights of edges of mst


// Prim's Algorithm to find MST sum
int prim(int v, vector<vector<pair<int, int>>> &adj)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> vis(v, 0); // visited array

  pq.push({0, 0}); // {weight, node}
  int sum = 0;

  while (!pq.empty())
  {
    auto it = pq.top();
    pq.pop();
    int wt = it.first;
    int node = it.second;

    if (vis[node] == 1)
      continue;

    vis[node] = 1;
    sum += wt;

    for (auto x : adj[node])
    {
      int adjnode = x.first;
      int edw = x.second;
      if (!vis[adjnode])
      {
        pq.push({edw, adjnode});
      }
    }
  }
  return sum;
}

int main()
{
  int v, e;
  cout << "Enter number of vertices and edges: ";
  cin >> v >> e;

  vector<vector<pair<int, int>>> adj(v);

  cout << "Enter edges in format (u v w):" << endl;
  for (int i = 0; i < e; i++)
  {
    int u, vtx, wt;
    cin >> u >> vtx >> wt;
    adj[u].push_back({vtx, wt});
    adj[vtx].push_back({u, wt}); // because undirected graph
  }

  int mst_weight = prim(v, adj);
  cout << "Sum of weights of MST: " << mst_weight << endl;

  return 0;
}
