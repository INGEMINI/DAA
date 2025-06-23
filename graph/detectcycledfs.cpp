#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[])
{
  vis[node] = 1;

  for (auto adjnode : adj[node])
  {
    if (!vis[adjnode])
    {
      if (dfs(adjnode, node, vis, adj) == true)
      {
        return true;
      }
    }
    else if (adjnode != parent)
    {
      return true;
    }
  }
  return false;
}

bool iscycle(int v, vector<int> adj[])
{
  vector<int> vis(v, 0);
  for (int i = 0; i < v; i++)
  {
    if (!vis[i])
    {
      if (dfs(i, -1, vis, adj) == true)
      {
        return true;
      }
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
