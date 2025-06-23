#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int> &wt, vector<int> &val, int n)
{
  // Create a 2D DP table
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

  // Fill the DP table
  for (int i = 1; i <= n; i++)
  {
    for (int w = 1; w <= W; w++)
    {
      if (wt[i - 1] <= w)
      {
        // If the item can be included
        dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
      }
      else
      {
        // If the item cannot be included
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  // The maximum value is stored in dp[n][W]
  return dp[n][W];
}

int main()
{
  int n, W;

  // Input number of items and knapsack capacity
  cout << "Enter number of items: ";
  cin >> n;
  cout << "Enter the capacity of the knapsack: ";
  cin >> W;

  vector<int> val(n), wt(n);

  // Input values and weights of the items
  cout << "Enter the values of the items: ";
  for (int i = 0; i < n; i++)
  {
    cin >> val[i];
  }

  cout << "Enter the weights of the items: ";
  for (int i = 0; i < n; i++)
  {
    cin >> wt[i];
  }

  // Call the knapsack function
  int result = knapsack(W, wt, val, n);
  cout << "The maximum value that can be obtained: " << result << endl;

  return 0;
}
