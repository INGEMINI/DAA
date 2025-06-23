// dijktra and bellman were single src shortest path
// floys is multi src shortest path
// detects -ve cycle also

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void algo(vector<vector<int>> &matrix)
{
  int n = matrix.size();

  // Convert -1 to large number for computation
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (matrix[i][j] == -1)
      {
        matrix[i][j] = 1e9;
      }
      if (i == j)
      {
        matrix[i][j] = 0;
      }
    }
  }

  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
      }
    }
  }

  // if we wnat to detect -ve cycle then this for loop is for that purpose
  for (int i = 0; i < n; i++)
  {
    if (matrix[i][i] < 0)
    {
      cout << "cycle is -ve" << endl;
    }
  }

  // Convert 1e9 back to -1 to indicate no path

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (matrix[i][j] == 1e9)
      {
        matrix[i][j] = -1;
      }
      if (i == j)
      {
        matrix[i][j] = 0;
      }
    }
  }

  // Display result
  cout << "Shortest distance matrix:\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int n;
  cout << "Enter number of nodes: ";
  cin >> n;

  vector<vector<int>> matrix(n, vector<int>(n));
  cout << "Enter the adjacency matrix (use -1 for no path):\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }

  algo(matrix);

  return 0;
}