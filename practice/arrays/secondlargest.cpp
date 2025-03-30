#include <iostream>
using namespace std;

int secondlar(int arr[], int n)
{

  int first = -1, second = -1;

  for (int i = 0; i < n; i++)
  {

    if (arr[i] > first)
    {
      second = first;
      first = arr[i];
    }

    else if (arr[i] > second && arr[i] < first)
    {
      second = arr[i];
    }
  }
  return second;
}

int main()
{
  int arr[] = {12, 13, 14, 15, 16, 12, 10, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "second largest element is " << secondlar(arr, n);
  return 0;
}