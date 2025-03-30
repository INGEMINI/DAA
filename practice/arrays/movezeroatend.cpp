#include <iostream>
using namespace std;

void movezero(int arr[], int n)
{
  int j = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] != 0)
    {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 0, 0, 3, 9, 0};
  int n = sizeof(arr) / sizeof(arr[0]);
  movezero(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}