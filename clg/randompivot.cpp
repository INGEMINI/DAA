#include <iostream>
#include <cstdlib> // For rand()
using namespace std;

int comparisons = 0, swaps = 0;

// Function to choose a random pivot and partition the array
int partition(int arr[], int low, int high)
{
  // Selecting a random pivot
  int randomIndex = low + rand() % (high - low + 1);
  swap(arr[randomIndex], arr[high]); // Move random pivot to end
  swaps++;                           // Increment swap count

  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    comparisons++; // Counting comparisons
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]); // Swap smaller elements to the left
      swaps++;              // Increment swap count
    }
  }
  swap(arr[i + 1], arr[high]); // Place pivot in correct position
  swaps++;                     // Increment swap count
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

// Function to reset counts and call sorting
void processArray(int arr[], int n)
{
  comparisons = 0, swaps = 0; // Reset counters
  quickSort(arr, 0, n - 1);

  // Print sorted array
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  // Print counts
  cout << "comparisons = " << comparisons << endl;
  cout << "swaps = " << swaps << endl; // Display the number of swaps
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
