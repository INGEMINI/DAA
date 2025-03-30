#include <iostream>
#include <vector>
using namespace std;

void findMaxOccurrence(vector<char> &arr, int n)
{
  vector<int> count(26, 0); // Frequency array for 'a' to 'z'

  // Step 1: Count frequency of each alphabet
  for (char ch : arr)
    count[ch - 'a']++; // Convert 'a'-'z' to 0-25 index

  // Step 2: Find the maximum frequency
  int maxFreq = 0;
  for (int i = 0; i < 26; i++)
    maxFreq = max(maxFreq, count[i]);

  // Step 3: Check if duplicates exist
  bool hasDuplicate = false;
  for (int i = 0; i < 26; i++)
  {
    if (count[i] > 1)
    {
      hasDuplicate = true;
      break;
    }
  }

  // Step 4: Print all characters with max frequency
  if (hasDuplicate)
  {
    for (int i = 0; i < 26; i++)
    {
      if (count[i] == maxFreq)
        cout << (char)('a' + i) << " - " << maxFreq << endl;
    }
  }
  else
  {
    cout << "No Duplicates Present" << endl;
  }
}

int main()
{
  int t, n;
  cin >> t; // Number of test cases
  while (t--)
  {
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i]; // Input alphabets
    findMaxOccurrence(arr, n);
  }
  return 0;
}
