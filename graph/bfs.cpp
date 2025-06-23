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

vector<int> bfs(int v, vector<int> adj[])
{

  queue<int> q;
  vector<int> bfs;
  int vis[v] = {0};

  vis[0] = 1;

  q.push(0);
  while (!q.empty())
  {

    int node = q.front();
    ;
    q.pop();
    bfs.push_back(node);

    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        vis[it] = 1;
        q.push(it);
      }
    }
  }
  return bfs;
}
int main()
{
  vector<int> adj[6];
  addedge(adj, 0, 1);
  addedge(adj, 1, 2);
  addedge(adj, 1, 3);
  addedge(adj, 0, 4);

  vector<int> ans = bfs(5, adj);

  printedge(ans);
  return 0;
}