class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return lcsHelper(text1, text2, m, n, dp);
    }

private:
    int lcsHelper(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i - 1] == text2[j - 1]) {
            dp[i][j] = 1 + lcsHelper(text1, text2, i - 1, j - 1, dp);
        } else {
            dp[i][j] = max(lcsHelper(text1, text2, i - 1, j, dp),
                           lcsHelper(text1, text2, i, j - 1, dp));
        }

        return dp[i][j];
    }
};
