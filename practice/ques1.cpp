#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b)
{
  return a.second < b.second;
}
vector<int> taskselection(vector<pair<int, int>> task)
{
  vector<int> res;
  sort(task.begin(), task.end(), comparator);
  int cnt = 0;
  int t = 0;
  for (int i = 0; i < task.size(); i++)
  {
    if (t + task[i].first <= task[i].second)
    {
      t += task[i].first;
      res.push_back(i + 1);
      cnt++;
    }
  }

  res.push_back(cnt);
  return res;
}

int main()
{
  vector<pair<int, int>> vec;
  vec.push_back({2, 2});
  vec.push_back({1, 3});
  vec.push_back({3, 8});
  vec.push_back({2, 6});
  vec.push_back({2, 2});
  vec.push_back({2, 5});
  vec.push_back({1, 3});

  vector<int> nums;
  nums = taskselection(vec);
  cout << "maximum no of tasks = " << nums[nums.size() - 1] << endl;
  for (int j = 0; j < nums.size() - 1; j++)
  {
    cout << nums[j] << " ";
  }
  return 0;
}