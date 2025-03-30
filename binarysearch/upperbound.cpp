#include <iostream>
using namespace std;

void lowerbound(int arr[], int target)
{
  int n = 7;
  // int n = sizeof(arr) / sizeof(arr[0]);
  int l = 0;
  int r = n - 1;
  int ans = n;

  while (l <= r)
  {
    int mid = l + (r - l) / 2;
    if (arr[mid] > target)
    {
      ans = mid;
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }

  cout << "index is " << ans;
}

int main()
{
  int arr[] = {1, 2, 3, 5, 6, 7, 8};
  int target = 5;
  lowerbound(arr, target);
  return 0;
}

//stl function
//upper_bound(arr.begin(),arr.end(),n);