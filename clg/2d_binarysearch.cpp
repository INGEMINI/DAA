#include <iostream>
#include <vector>
using namespace std;

bool binarySearch2D(vector<vector<int>> &matrix, int target)
{
  int m = matrix.size(), n = matrix[0].size();
  int left = 0, right = m * n - 1;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    int row = mid / n, col = mid % n; // Convert 1D index to 2D row & col

    if (matrix[row][col] == target)
      return true;
    else if (matrix[row][col] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return false; // Target not found
}

int main()
{
  int m, n, target;
  cin >> m >> n; // Input rows and columns

  vector<vector<int>> matrix(m, vector<int>(n));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j]; // Input matrix elements

  cin >> target; // Element to search

  if (binarySearch2D(matrix, target))
    cout << "Element Found" << endl;
  else
    cout << "Element Not Found" << endl;

  return 0;
}
