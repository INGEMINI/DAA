#include <iostream>
#include <vector>
using namespace std;

vector<int> fibonacci(int n)
{
  // Create an array to store Fibonacci numbers up to n
  vector<int> dp(n + 1);

  // Base cases
  dp[0] = 0;
  dp[1] = 1;

  // Fill the dp array by solving the subproblems
  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  // Return the nth Fibonacci number
  return dp;
}

int main()
{
  int n;
  cout << "Enter the value of n: ";
  cin >> n;
  vector<int> ans = fibonacci(n);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  return 0;
}
