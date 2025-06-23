// this is my solution
// although its working for 5 test cases and giving tle and mle for rest but its my solution

// leetcode sol is of some website
class Solution
{
public:
  long long maximumCoins(vector<vector<int>> &coins, int k)
  {
    int min = 0, max = 0;
    int n = coins.size();

    for (int i = 0; i < n; i++)
    {

      for (int j = 0; j < 3; j++)
      {
        if (min > coins[i][0])
        {
          min = coins[i][0];
        }
        if (max < coins[i][1])
        {
          max = coins[i][1];
        }
      }
    }
    int len = max - min + 1;
    vector<int> final(len, 0);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
      int minindex = coins[i][0];
      int maxindex = coins[i][1];
      int value = coins[i][2];
      index = minindex;
      while (index >= minindex && index <= maxindex)
      {
        final[index] = value;
        index++;
      }
    }
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
      int temp = 0;
      int space = i;
      for (int j = i; j < (space + k); j++)
      {
        if (j < len)
        {
          temp += final[j];
        }
      }
      if (temp > sum)
      {
        sum = temp;
      }
    }
    return sum;
  }
};