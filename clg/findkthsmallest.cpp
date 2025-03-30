#include <iostream>
#include <vector>
#include <algorithm> // For min_element, max_element
using namespace std;

void findKthElement(vector<int> &arr, int n, int k)
{
  if (k > n || k <= 0)
  {
    cout << "not present" << endl;
    return;
  }

  // Step 1: Find min and max values in the array
  int min_val = *min_element(arr.begin(), arr.end());
  int max_val = *max_element(arr.begin(), arr.end());

  // Step 2: Create a frequency array with offset for negative numbers
  int range = max_val - min_val + 1;
  vector<int> count(range, 0);

  // Step 3: Fill the count array (offset adjusted)
  for (int num : arr)
    count[num - min_val]++;

  // Step 4: Find the Kth smallest element
  int position = 0;
  for (int i = 0; i < range; i++)
  {
    position += count[i];
    if (position >= k)
    {
      cout << (i + min_val) << endl; // Adjust back to original number
      return;
    }
  }

  // If we never found the Kth element, it means it is missing
  cout << "not present" << endl;
}

int main()
{
  int t, n, k;
  cin >> t; // Number of test cases
  while (t--)
  {
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    cin >> k;
    findKthElement(arr, n, k);
  }
  return 0;
}
