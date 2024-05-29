class Solution
{
public:
    int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
    {
        if (i <= 0 or j <= 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text1[i - 1] == text2[j - 1])
            return dp[i][j] = 1 + solve(text1, text2, i - 1, j - 1, dp);
        return dp[i][j] = max(solve(text1, text2, i - 1, j, dp), solve(text1, text2, i, j - 1, dp));
    }
    int countMin(string S)
    {
        // complete the function here
        int n = S.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        string T = S;
        reverse(T.begin(), T.end());
        return n - solve(S, T, n, n, dp);
    }
};