#include <iostream>
#include <vector>
#include <algorithm> // For min_element, max_element
using namespace std;

void findCommonElements(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
  // Step 1: Find min and max values in arr1
  int min_val = *min_element(arr1.begin(), arr1.end());
  int max_val = *max_element(arr1.begin(), arr1.end());

  int range = max_val - min_val + 1;
  vector<bool> count(range, false); // Frequency array for arr1 elements

  // Step 2: Mark elements of arr1 in count[]
  for (int num : arr1)
    count[num - min_val] = true;

  // Step 3: Find common elements while iterating arr2
  bool found = false;
  for (int num : arr2)
  {
    if (count[num - min_val])
    { // No need for extra condition!
      cout << num << " ";
      count[num - min_val] = false; // Avoid duplicates
      found = true;
    }
  }

  // Step 4: If no common elements, print message
  if (!found)
    cout << "No Common Elements";

  cout << endl;
}

int main()
{
  int m, n;
  cin >> m;
  vector<int> arr1(m);
  for (int i = 0; i < m; i++)
    cin >> arr1[i];

  cin >> n;
  vector<int> arr2(n);
  for (int i = 0; i < n; i++)
    cin >> arr2[i];

  findCommonElements(arr1, m, arr2, n);
  return 0;
}
