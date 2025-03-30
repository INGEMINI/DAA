#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // normal vector (dynamic vector)
  vector<int> v = {1, 2, 3, 4, 5};
  cout << "vector<int>arr:";
  for (int num : v)
  {
    cout << num << " ";
  }
  cout << endl;

  // vector array ( fixed size vector)
  vector<int> arr1[2];
  arr1[0] = {10, 20};
  arr1[1] = {10, 20, 30};
  cout << "vector<int> arr[]: " << endl;
  for (int i = 0; i < 2; i++)
  {
    for (int num : arr1[i])
      cout << num << " ";
    cout << endl;
  }

  // vector 2d array(dynamic 2d vector)
  vector<vector<int>> v2 = {{10, 20}, {10, 20, 30, 40}};
  cout << "vector<vector<int>>arr : " << endl;
  for (auto &row : v2)
  {
    for (int num : row)
    {
      cout << num << " ";
      cout << endl;
    }
  }

  // vector 2d array(partially 3d array)
  vector<vector<int>> arr2[2];
  arr2[0] = {{1, 2}, {1, 2, 3}};
  arr2[1] = {{4, 5, 6}, {7, 8, 9, 10}};
  cout << "vector<vector<int>> arr[] : " << endl;
  for (int i = 0; i < 2; i++)
  {
    cout << "group " << i << ":" << endl;
    for (auto &row : arr2[i])
    {
      for (int num : row)
      {
        cout << num << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
