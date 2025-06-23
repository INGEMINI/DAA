#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void addedge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void printedge(vector<int> &adj)
{
  for (int i = 0; i < adj.size(); i++)
  {
    cout << adj[i] << " ";
  }
}
void dfsmain(int node, vector<int> adj[], int vis[], vector<int> &dfs)
{
  vis[node] = 1;
  dfs.push_back(node);
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      dfsmain(it, adj, vis, dfs);
    }
  }
}

vector<int> dfs(int v, vector<int> adj[])
{

  vector<int> dfs;
  int vis[v] = {0};
  int start = 0;

  dfsmain(start, adj, vis, dfs);
  return dfs;
}
int main()
{
  vector<int> adj[6];
  addedge(adj, 0, 1);
  addedge(adj, 1, 2);
  addedge(adj, 1, 3);
  addedge(adj, 0, 4);

  vector<int> ans = dfs(5, adj);

  printedge(ans);
  return 0;
}