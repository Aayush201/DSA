class Solution
{

public:
    int solve(int n, int m, string &str1, string &str2, vector<vector<int>> &dp)
    {
        if (n <= 0 || m <= 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];

        if (str1[n - 1] == str2[m - 1])
            return dp[n][m] = 1 + solve(n - 1, m - 1, str1, str2, dp);
        return dp[n][m] = max(solve(n - 1, m, str1, str2, dp), solve(n, m - 1, str1, str2, dp));
    }
    int minOperations(string str1, string str2)
    {
        // Your code goes here
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return n + m - 2 * solve(n, m, str1, str2, dp);
    }
};