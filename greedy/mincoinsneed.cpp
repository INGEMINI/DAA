#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  vector<int> coins;
  coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int val;
  cin >> val;
  int i = coins.size() - 1;
  int cnt = 0;
  while (i >= 0)
  {
    if (coins[i] > val)
    {
      i--;
      continue;
    }
    if (coins[i] == val)
    {
      cnt++;

      break;
    }
    while (coins[i] < val)
    {
      cnt++;
      val = val - coins[i];
    }
    i--;
  }
  cout << "coins neeeded r" << cnt;
}