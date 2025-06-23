sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b))

// Step 2: Sort jobs by profit descending
  sort(jobIndex.begin(), jobIndex.end(), [&](int a, int b)
       { return profit[a] > profit[b]; });