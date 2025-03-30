#include <iostream>
#include <cstdlib> // For rand()
using namespace std;

// Function to partition the array (Lomuto Partition)
int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] <= pivot)
    { // If current element is smaller than the pivot
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]); // Move pivot to correct position
  return i + 1;
}

// QuickSelect function to find Kth smallest element
int quickSelect(int arr[], int low, int high, int k)
{
  if (low <= high)
  {
    int pi = partition(arr, low, high); // Get partition index

    if (pi == k - 1) // If pivot is at Kth position
      return arr[pi];
    else if (pi > k - 1)
      return quickSelect(arr, low, pi - 1, k); // Search left side
    else
      return quickSelect(arr, pi + 1, high, k); // Search right side
  }
  return -1; // If K is out of range
}

// Function to process test cases
void processArray(int arr[], int n, int k)
{
  if (k > 0 && k <= n)
  {
    int result = quickSelect(arr, 0, n - 1, k);
    cout << result << endl;
  }
  else
  {
    cout << "not present" << endl;
  }
}

int main()
{
  int t, n, k;
  cin >> t; // Number of test cases
  while (t--)
  {
    cin >> n; // Size of array
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i]; // Input array elements
    cin >> k;        // Kth element to find
    processArray(arr, n, k);
  }
  return 0;
}
