class Solution
{
public:
    int solve(int n, int m, string &X, string &Y, vector<vector<int>> &dp)
    {
        if (n <= 0 || m <= 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];

        if (X[n - 1] == Y[m - 1])
            dp[n][m] = 1 + solve(n - 1, m - 1, X, Y, dp);
        else
            dp[n][m] = 0;
        solve(n - 1, m, X, Y, dp);
        solve(n, m - 1, X, Y, dp);
        return dp[n][m];
    }
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = INT_MIN;
        solve(n, m, S1, S2, dp);
        for (auto x : dp)
        {
            for (auto xx : x)
            {
                // cout << xx << " ";
                ans = max(ans, xx);
            }
            //  cout << endl;
        }
        return ans == INT_MIN ? 0 : ans;
    }
};