#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// topo sort is only valid for dag(directed acyclic graph)
// similar to topo sort
// here we use bfs+ indegree(no of incoming edges to node)
// here min 1 node has  indegree as 0

//note
//  Cycle Detection is easier
// In Kahn's, if the number of nodes in the final topo list < total nodes → there's a cycle.

// In DFS, cycle detection requires tracking recursion stack separately.

vector<int> kahnsort(int v, vector<int> adj[])
{
  int indegree[v] = {0};
  for (int i = 0; i < v; i++)
  {
    for (auto it : adj[i])
    {
      indegree[it]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < v; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }
  vector<int> ans;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (auto it : adj[node])
    {
      indegree[it]--;
      if (indegree[it] == 0)
      {
        q.push(it);
      }
    }
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
  vector<int> adj[5];
  addedge(adj, 0, 1);
  addedge(adj, 1, 2);
  addedge(adj, 1, 3);
  addedge(adj, 3, 4);

  vector<int> ans = kahnsort(5, adj);

  printedge(ans);
  return 0;
}