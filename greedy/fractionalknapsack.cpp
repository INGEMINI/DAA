#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static bool compare(pair<int, int> p1, pair<int, int> p2)
{
  return ((double)p1.first / p1.second) > ((double)p2.first / p2.second);
}

double algo(vector<int> &price, vector<int> &wt, int w)
{
  vector<pair<int, int>> stock;
  int n = price.size();

  for (int i = 0; i < n; i++)
  {
    stock.push_back({price[i], wt[i]});
  }
  sort(stock.begin(), stock.end(), compare);

  double totalamt = 0;
  int wtsum = 0;

  for (int i = 0; i < n; i++)
  {
    if ((wtsum + stock[i].second) < w)
    {
      totalamt += stock[i].first;
      wtsum = wtsum + stock[i].second;
    }
    else
    {
      if (wtsum < w)
      {
        int restwt = w - wtsum;
        int restamt = ((double)stock[i].first / stock[i].second) * restwt;
        totalamt += restamt;
        break;
      }
    }
  }
  return totalamt;
}

int main()
{
  int n, w;
  vector<int> price, wt;
  int temp1, temp2;
  cout << "enter no of products" << endl;
  cin >> n;
  cout << "now enter values for all serial vise : " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> temp1 >> temp2;
    price.push_back(temp1);
    wt.push_back(temp2);
  }
  cout << "enter wt (total allowed)" << endl;
  cin >> w;
  double ans;
  ans = algo(price, wt, w);
  cout << "ans is " << ans;
  return 0;
}