// Problem Link :  https://www.geeksforgeeks.org/problems/edit-distance3702/1

class Solution
{
public:
    int solve(int n, int m, string &s, string &t, vector<vector<int>> &dp)
    {
        if (n == 0 && m == 0)
            return 0;
        if (n == 0)
            return m;
        if (m == 0)
            return n;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (s[n - 1] == t[m - 1])
            return dp[n][m] = solve(n - 1, m - 1, s, t, dp);
        else
        {
            int val1 = 1 + solve(n - 1, m, s, t, dp);
            int val2 = 1 + solve(n, m - 1, s, t, dp);
            int val3 = 1 + solve(n - 1, m - 1, s, t, dp);
            return dp[n][m] = min({val1, val2, val3});
        }
    }
    int editDistance(string s, string t)
    {
        // Code here
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, s, t, dp);
    }
};