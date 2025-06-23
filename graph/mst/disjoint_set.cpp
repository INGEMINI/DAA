#include <iostream>
#include <vector>
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

int main()
{
  disjoint ds(7);
  ds.unionbyrank(1, 2);
  ds.unionbyrank(2, 3);
  ds.unionbyrank(4, 5);
  ds.unionbyrank(6, 7);
  ds.unionbyrank(5, 6);

  if (ds.findupar(3) == ds.findupar(7))
  {
    cout << "same" << endl;
  }

  else
  {
    cout << "different parent" << endl;
  }

  ds.unionbyrank(3, 7);

  if (ds.findupar(3) == ds.findupar(7))
  {
    cout << "same" << endl;
  }

  else
  {
    cout << "different parent" << endl;
  }

  cout << "now tring for union by size " << endl;

  disjoint ds2(7);
  ds2.unionbysize(1, 2);
  ds2.unionbysize(2, 3);
  ds2.unionbysize(4, 5);
  ds2.unionbysize(6, 7);
  ds2.unionbysize(5, 6);

  if (ds2.findupar(3) == ds2.findupar(7))
  {
    cout << "same" << endl;
  }

  else
  {
    cout << "different parent" << endl;
  }

  ds2.unionbysize(3, 7);

  if (ds2.findupar(3) == ds2.findupar(7))
  {
    cout << "same" << endl;
  }

  else
  {
    cout << "different parent" << endl;
  }
  return 0;
}