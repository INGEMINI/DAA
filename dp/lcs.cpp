// Longest Common Subsequence (LCS)
// Problem:
// Given two strings, find the length of their longest subsequence which is common to both
// Example:
// String 1 = "abcde"
// String 2 = "ace"

// LCS = "ace" → length = 3

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                // If characters match, include it in LCS
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                // Else, take maximum by excluding one character from either string
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];  // Length of LCS
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    cout << "Length of Longest Common Subsequence is: " << lcs(s1, s2) << endl;
    return 0;
}
