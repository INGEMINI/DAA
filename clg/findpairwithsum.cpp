#include <iostream>
#include <vector>
#include <algorithm> // For sorting
using namespace std;

void findPairWithSum(vector<int> &arr, int n, int key)
{
  sort(arr.begin(), arr.end()); // Step 1: Sort the array (O(n log n))

  int low = 0, high = n - 1;

  // Step 2: Two-pointer approach (O(n))
  while (low < high)
  {
    int sum = arr[low] + arr[high];

    if (sum == key)
    { // Found the pair
      cout << arr[low] << " " << arr[high] << endl;
      return;
    }
    else if (sum < key)
      low++; // Move left pointer to increase sum
    else
      high--; // Move right pointer to decrease sum
  }

  // If no such pair is found
  cout << "No Such Elements Exist" << endl;
}

int main()
{
  int t, n, key;
  cin >> t; // Number of test cases
  while (t--)
  {
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i]; // Input array elements
    cin >> key;      // Input key sum
    findPairWithSum(arr, n, key);
  }
  return 0;
}
