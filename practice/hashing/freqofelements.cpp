#include <iostream>
#include <unordered_map>
using namespace std;

void freqele(int arr[], int n)
{

  unordered_map<int, int> freq;
  for (int i = 0; i < n; i++)
  {

    freq[arr[i]]++;
  }

  for (auto val : freq)
  {
    cout << val.first << " -> " << val.second << endl;
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 5, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  freqele(arr, n);
  return 0;
}