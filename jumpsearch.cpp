#include <cmath>
#include <iostream>
#include <vector>

// #include <bits/stdc++.h>
using namespace std;

int js(vector<int> &v, int key)
{
  int n = v.size();
  int step = sqrt(n), prev = 0;
  while (prev < n && v[min(step, n) - 1] < key)
  {
    prev = step;
    step += sqrt(n);
  }

  for (int i = prev; i < min(step, n); i++)
  {
    if (v[i] == key)
      return i;
  }
  return -1;
}

int main()
{
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 15};
  int key;
  cout << "enter elements for search";
  cin >> key;
  int index = js(v, key);
  if (index != -1)
  {
    cout << "element found at index " << index << endl;
  }

  else
  {
    cout << "element not found" << endl;
  }

  return 0;
}