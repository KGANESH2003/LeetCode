#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        if (dp[i][j] != -1) return dp[i][j];

        if (S1[i] == S2[j]) {
            return dp[i][j] = minDistanceUtil(S1, S2, i - 1, j - 1, dp);
        } else {
            return dp[i][j] = 1 + min(minDistanceUtil(S1, S2, i - 1, j - 1, dp),
                                      min(minDistanceUtil(S1, S2, i - 1, j, dp),
                                          minDistanceUtil(S1, S2, i, j - 1, dp)));
        }
    }

    int minDistance(string word1, string word2) {  // Renamed function
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return minDistanceUtil(word1, word2, n - 1, m - 1, dp);
    }
};
