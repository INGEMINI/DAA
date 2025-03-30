#include <iostream>
using namespace std;

// Partition function for Quick Sort
int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Function to check for duplicates
void checkDuplicates(int arr[], int n)
{
  quickSort(arr, 0, n - 1); // Sort the array using Quick Sort (O(n log n))

  int i = 0;
  while (i < n - 1)
  {
    if (arr[i] == arr[i + 1])
    { // Check adjacent elements for duplicates
      cout << "YES" << endl;
      return;
    }
    i++;
  }
  cout << "NO" << endl;
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
      cin >> arr[i]; // Input array elements
    checkDuplicates(arr, n);
  }
  return 0;
}
