#include <iostream>
#include <cmath>
using namespace std;

void jumpSearch(int arr[], int n, int key)
{
  int step = sqrt(n); // Step size (square root of n)
  int left = 0, right = step, comparisons = 0;

  // Jumping Phase: Find the correct block
  while (right < n && arr[right] < key)
  {
    left = right;
    right += step;
    comparisons++; // Count the comparison when moving the right pointer
  }

  // Linear Search within the identified block
  for (int i = left; i < min(right, n); i++)
  {
    comparisons++; // Count the comparison in linear search
    if (arr[i] == key)
    {
      cout << "Present " << comparisons << endl;
      return;
    }
  }

  cout << "Not Present " << comparisons << endl;
}

int main()
{
  int t, n, key;
  cin >> t; // Number of test cases
  while (t--)
  {
    cin >> n; // Size of array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i]; // Array elements
    }
    cin >> key;              // Key to be searched
    jumpSearch(arr, n, key); // Perform Jump Search
  }
  return 0;
}
