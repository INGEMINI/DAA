#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
  int left = 0, right = n - 1, comparisons = 0;
  while (left <= right)
  {
    comparisons++;
    int mid = left + (right - left) / 2;
    if (arr[mid] == key)
    {
      cout << "Present " << comparisons << endl;
      return 1;
    }
    else if (arr[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  cout << "Not Present " << comparisons << endl;
  return 0;
}

int main()
{
  int t, n, key;
  cin >> t;
  while (t--)
  {
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    cin >> key;
    binarySearch(arr, n, key);
  }
  return 0;
}
