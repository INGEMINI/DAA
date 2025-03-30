#include <iostream>
#include <unordered_map>
using namespace std;

int firstele(int arr[], int n)
{

  unordered_map<int, int> freq;
  for (int i = 0; i < n; i++)
  {
    if (freq[arr[i]] > 0)
    {
      return arr[i];
    }

    freq[arr[i]]++;
  }

  return -1;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 5, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "first repeating element : " << firstele(arr, n);
  return 0;
}