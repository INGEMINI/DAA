#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// min heap ds { dist,node}..shorter dist at d top
// in this algo we find dist from src node to all other nodes
// not applicable for -ve cycle
vector<int> algo(int v, vector<vector<pair<int, int>>> adj, int s)
{

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  // thats how we generate min heap using pq
  vector<int> dist(v, 1e9);

  dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty())
  {
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (auto it : adj[node])
    {
      int edgeweight = it.second;
      int adjnode = it.first;
      if (dis + edgeweight < dist[adjnode])
      {
        dist[adjnode] = dis + edgeweight;
        pq.push({dist[adjnode], adjnode});
      }
    }
  }
  return dist;
}

int main()
{
  int v, e;
  cout << "enter no of v and edges";
  cin >> v >> e;
  vector<vector<pair<int, int>>> adj(v);
  cout << "enter edges in format ( u v wt) : " << endl;

  for (int i = 0; i < e; i++)
  {
    int u, vtx, wt;
    cin >> u >> vtx >> wt;
    adj[u].push_back({vtx, wt});
    adj[vtx].push_back({u, wt});
  }
  int src;
  cout << "enter src node";
  cin >> src;

  vector<int> ans = algo(v, adj, src);
  cout << "ans is from node src :" << src << endl;

  for (int i = 0; i < v; i++)
  {
    cout << "node" << i << ": " << ans[i] << endl;
  }
  return 0;
}