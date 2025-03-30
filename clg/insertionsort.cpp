#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
  int comparisons = 0, shifts = 0;

  for (int i = 1; i < n; i++)
  {
    int key = arr[i], j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      comparisons++;       // Count comparison
      arr[j + 1] = arr[j]; // Shift element
      j--;
      shifts++;
    }
    arr[j + 1] = key; // Insert element
    shifts++;
  }

  // Print sorted array
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  // Print number of comparisons and shifts
  cout << "Comparisons: " << comparisons << endl;
  cout << "Shifts: " << shifts << endl;
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
    insertionSort(arr, n);
  }
  return 0;
}
