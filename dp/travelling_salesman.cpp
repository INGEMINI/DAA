#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to solve the TSP problem using Dynamic Programming
int tsp(const vector<vector<int>> &dist, int n)
{
  // DP table where dp[i][j] will hold the minimum cost to visit all cities from city i to city j
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // Base case: Direct distances between all pairs of cities
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i != j)
      {
        dp[i][j] = dist[i][j]; // Initially, set the direct distance
      }
    }
  }

  // DP solution
  for (int len = 3; len <= n; len++)
  { // len is the length of the subpath
    for (int i = 0; i < n - len + 1; i++)
    {                      // Start city
      int j = i + len - 1; // End city
      for (int k = i + 1; k < j; k++)
      { // Intermediate city between i and j
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  return dp[0][n - 1]; // The minimum cost to visit all cities starting and ending at city 0
}

int main()
{
  int n;
  cout << "Enter the number of cities: ";
  cin >> n;

  vector<vector<int>> dist(n, vector<int>(n));

  cout << "Enter the distance matrix:\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> dist[i][j];
    }
  }

  // Solve the TSP problem using DP
  int result = tsp(dist, n);

  cout << "The minimum cost of the TSP tour is: " << result << endl;
  return 0;
}
