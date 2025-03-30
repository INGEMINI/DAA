#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class solution
{

public:
  vector<int> bfstraversal(int v, vector<vector<int>> edges, int start)
  {
    vector<vector<int>> adj(v);

    for (auto edge : edges)
    {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    vector<int> result;
    vector<bool> visited(v, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      result.push_back(node);
      for (int neighbor : adj[node])
      {
        if (!visited[neighbor])
        {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }

    return result;
  }
};
int main()
{

  int v = 5;

  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};

  int start = 0;

  solution sol;

  vector<int> bfs_result = sol.bfstraversal(v, edges, start);

  cout << "bfs traversal";
  for (int node : bfs_result)
  {
    cout << node << " ";
  }
  cout << endl;
  return 0;
}