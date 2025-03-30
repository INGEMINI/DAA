#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key)
{
  int left = 0, right = n - 1, result = -1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == key)
    {
      result = mid;
      right = mid - 1;
    }
    else if (arr[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return result;
}

int lastOccurrence(int arr[], int n, int key)
{
  int left = 0, right = n - 1, result = -1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == key)
    {
      result = mid;
      left = mid + 1;
    }
    else if (arr[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return result;
}

void countOccurrences(int arr[], int n, int key)
{
  int first = firstOccurrence(arr, n, key);
  if (first == -1)
  {
    cout << "Key not present" << endl;
    return;
  }
  int last = lastOccurrence(arr, n, key);
  cout << key << " - " << (last - first + 1) << endl;
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
    countOccurrences(arr, n, key);
  }
  return 0;
}
