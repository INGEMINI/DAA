#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(vector<int> &arr)
{
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // length of the chain
  for (int len = 2; len < n; len++)
  { // len is the gap between i and j
    for (int i = 0; i < n - len; i++)
    {
      int j = i + len;
      dp[i][j] = INT_MAX;
      for (int k = i + 1; k < j; k++)
      {
        int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
        dp[i][j] = min(dp[i][j], cost);
      }
    }
  }

  return dp[0][n - 1];
}

int main()
{
  int n;
  cout << "Enter number of matrices + 1: ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter dimensions array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << "Minimum number of multiplications is: " << matrixChainMultiplication(arr) << endl;
  return 0;
}
