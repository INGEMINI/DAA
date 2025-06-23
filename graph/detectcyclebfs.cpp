#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool detect(int src, vector<int> adj[], int vis[])
{
  vis[src] = 1;
  queue<pair<int, int>> q;
  q.push({src, -1});
  while (!q.empty())
  {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();

    for (auto adjnode : adj[node])
    {
      if (!vis[adjnode])
      {
        vis[adjnode] = 1;
        q.push({adjnode, node});
      }
      else if (parent != adjnode)
      {
        return true;
      }
    }
  }
  return false;
}

// as we need to cover for all components of graph so

bool iscycle(int v, vector<int> adj[])
{
  int vis[v] = {0};
  for (int i = 0; i < v; i++)
  {
    if (!vis[i])
    {
      if (detect(i, adj, vis))
        return true;
    }
  }
  return false;
}

void addedge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main()
{
  vector<int> adj[6];
  addedge(adj, 0, 1);
  addedge(adj, 1, 3);
  addedge(adj, 5, 3);
  addedge(adj, 5, 4);
  addedge(adj, 2, 4);
  addedge(adj, 0, 2);

  bool ans = iscycle(5, adj);

  cout << ans;
  return 0;
}
