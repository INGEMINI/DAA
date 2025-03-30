#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
  int comparisons = 0, swaps = 0;
  bool isSorted = true; // Flag to check if sorting is needed

  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;

    for (int j = i + 1; j < n; j++)
    {
      comparisons++; // Count comparison
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
        isSorted = false; // If we find a smaller element, array isn't sorted
      }
    }

    if (minIndex != i)
    {
      swap(arr[i], arr[minIndex]);
      swaps++; // Count swap
    }

    // If no swaps were made in this pass, the array is already sorted
    if (isSorted)
      break;
  }

  // Print sorted array
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  // Print total comparisons and swaps
  cout << "Comparisons: " << comparisons << endl;
  cout << "Swaps: " << swaps << endl;
}

int main()
{
  int t, n;
  cin >> t; // Number of test cases
  while (t--)
  {
    cin >> n; // Size of array
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i]; // Array input
    selectionSort(arr, n);
  }
  return 0;
}
