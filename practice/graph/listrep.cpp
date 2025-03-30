#include <iostream>
#include <vector>
using namespace std;

class graph
{

public:
  vector<vector<int>> adj;
  graph(int v)
  {
    adj.resize(v);
  }

  void addedge(int u, int v)
  {

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<int>> getgraph()
  {
    return adj;
  }
};

int main()
{

  int v = 5;
  graph g(v);
  g.addedge(0, 1);
  g.addedge(0, 4);
  g.addedge(1, 2);
  g.addedge(1, 3);
  g.addedge(1, 4);

  vector<vector<int>> graph = g.getgraph();

  for (int i = 0; i < v; i++)
  {

    cout << "adj [" << i << "]";

    for (int v : graph[i])
    {

      cout << v << " ";
    }
    cout << endl;
  }

  return 0;
}
