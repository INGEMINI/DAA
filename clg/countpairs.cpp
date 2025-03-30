#include <iostream>
#include <unordered_map>
using namespace std;

void countPairs(int arr[], int n, int k)
{
  unordered_map<int, int> freq;
  int count = 0;
  for (int i = 0; i < n; i++)
    freq[arr[i]]++;

  for (int i = 0; i < n; i++)
  {
    if (freq[arr[i] - k])
      count++;
  }
  cout << count << endl;
}

int main()
{
  int t, n, k;
  cin >> t;
  while (t--)
  {
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    cin >> k;
    countPairs(arr, n, k);
  }
  return 0;
}
