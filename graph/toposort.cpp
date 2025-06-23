#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// only valid for dag(directed acyclic graph)

void dfs(int node, int vis[], stack<int> &st, vector<int> adj[])
{
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      dfs(it, vis, st, adj);
    }
  }
  st.push(node);
}

vector<int> toposort(int v, vector<int> adj[])
{
  int vis[v] = {0};
  stack<int> st;
  for (int i = 0; i < v; i++)
  {
    if (!vis[i])
    {
      dfs(i, vis, st, adj);
    }
  }
  vector<int> ans;
  while (!st.empty())
  {
    ans.push_back(st.top());
    st.pop();
  }
  return ans;
}

void addedge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
}

void printedge(vector<int> &adj)
{
  for (int i = 0; i < adj.size(); i++)
  {
    cout << adj[i] << " ";
  }
}

int main()
{
  vector<int> adj[6];
  addedge(adj, 0, 1);
  addedge(adj, 1, 2);
  addedge(adj, 1, 3);
  addedge(adj, 3, 4);

  vector<int> ans = toposort(5, adj);

  printedge(ans);
  return 0;
}