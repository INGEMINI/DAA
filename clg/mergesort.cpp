#include <iostream>
using namespace std;

int comparisons = 0, inversions = 0;

// Merge function (Merge two sorted halves and count inversions)
void merge(int arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int L[n1], R[n2];

  // Copy data to temp arrays L[] and R[]
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = arr[mid + 1 + i];

  int i = 0, j = 0, k = left;

  // Merge L[] and R[] into arr[]
  while (i < n1 && j < n2)
  {
    comparisons++; // Counting comparisons
    if (L[i] <= R[j])
    {
      arr[k++] = L[i++];
    }
    else
    {
      arr[k++] = R[j++];
      inversions += (n1 - i); // Count inversions when R[j] is smaller
    }
  }

  // Copy remaining elements of L[]
  while (i < n1)
    arr[k++] = L[i++];

  // Copy remaining elements of R[]
  while (j < n2)
    arr[k++] = R[j++];
}

// Merge Sort function (Recursively sort and merge)
void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

// Function to reset counts and call sorting
void processArray(int arr[], int n)
{
  comparisons = 0, inversions = 0; // Reset counters
  mergeSort(arr, 0, n - 1);

  // Print sorted array
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  // Print counts
  cout << "comparisons = " << comparisons << endl;
  cout << "inversions = " << inversions << endl;
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
    processArray(arr, n);
  }
  return 0;
}
