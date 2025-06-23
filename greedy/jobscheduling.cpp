#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jobScheduling(vector<int> &profit, vector<int> &deadline)
{
  int n = profit.size();

  // Step 1: Create job index vector
  vector<int> jobIndex(n);
  for (int i = 0; i < n; i++)
    jobIndex[i] = i;

  // Step 2: Sort jobs by profit descending
  sort(jobIndex.begin(), jobIndex.end(), [&](int a, int b)
       { return profit[a] > profit[b]; });

  // Step 3: Find max deadline
  int maxDeadline = *max_element(deadline.begin(), deadline.end());
  vector<int> slot(maxDeadline + 1, -1); // slot[i] = -1 means free

  int count = 0, totalProfit = 0;

  // Step 4: Try to schedule each job
  for (int i = 0; i < n; i++)
  {
    int job = jobIndex[i];
    for (int j = deadline[job]; j > 0; j--)
    {
      if (slot[j] == -1)
      {
        slot[j] = job;
        count++;
        totalProfit += profit[job];
        break;
      }
    }
  }

  cout << "Jobs done: " << count << ", Total Profit: " << totalProfit << endl;
  return totalProfit;
}

int main()
{
  vector<int> profit = {100, 19, 27, 25};
  vector<int> deadline = {2, 1, 2, 1};

  jobScheduling(profit, deadline);

  return 0;
}
