// kruskals algo is used to find mst

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// disjoint set is mainly used in dynamic graphs
// disjoint set gives us 2 functions..findparent() & union()...

class disjoint
{
  vector<int> size, rank, parent;

public:
  disjoint(int n)
  {
    rank.resize(n + 1, 0); // n+1 bcz tree can be 0 or 1 based indexing
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int findupar(int node)
  {
    if (node == parent[node])
    {
      return node;
    }
    return parent[node] = findupar(parent[node]);
  }

  void unionbyrank(int u, int v)
  {
    int ulp_u = findupar(u);
    int ulp_v = findupar(v);
    if (ulp_u == ulp_v)
    {
      return;
    }
    if (rank[ulp_u] < rank[ulp_v])
    {
      parent[ulp_u] = ulp_v;
    }
    else if (rank[ulp_v] < rank[ulp_u])
    {
      parent[ulp_v] = ulp_u;
    }
    else
    {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

  void unionbysize(int u, int v)
  {
    int ulp_u = findupar(u);
    int ulp_v = findupar(v);
    if (ulp_u == ulp_v)
    {
      return;
    }

    if (size[ulp_u] < size[ulp_v])
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    else if (size[ulp_u] > size[ulp_v])
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
    else
    {

      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

class solution
{
public:
  int mst(int v, vector<vector<int>> adj[])
  {

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < v; i++)
    {
      for (auto it : adj[i])
      {

        int adjnode = it[0];
        int wt = it[1];
        int node = i;
        edges.push_back({wt, {node, adjnode}});
      }
    }

    disjoint ds(v);
    sort(edges.begin(), edges.end());
    int mstwt = 0;
    for (auto it : edges)
    {
      int wt = it.first;
      int u = it.second.first;
      int v = it.second.second;

      if (ds.findupar(u) != ds.findupar(v))
      {
        mstwt += wt;
        ds.unionbysize(u, v);
      }
    }
    return mstwt;
  }
};

int main()
{

  int t;
  cin >> t;
  while (t--)
  {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj[v];
    int i = 0;
    while (i++ < e)
    {
      int u, v, w;
      cin >> u >> v >> w;
      vector<int> t1, t2;
      t1.push_back(v);
      t1.push_back(w);
      adj[u].push_back(t1);
      t2.push_back(u);
      t2.push_back(w);
      adj[v].push_back(t2);
    }
    solution obj;
    cout << obj.mst(v, adj) << endl;
  }
  return 0;
}