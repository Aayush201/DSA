// Problem Link : https://www.geeksforgeeks.org/problems/find-if-string-is-k-palindrome-or-not1923/1

class Solution
{
public:
    int solve(string &str, string &revStr, int n, int m, vector<vector<int>> &dp)
    {
        if (n == 0 || m == 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (str[n - 1] == revStr[m - 1])
            return dp[n][m] = 1 + solve(str, revStr, n - 1, m - 1, dp);
        else
            return dp[n][m] = max(solve(str, revStr, n - 1, m, dp), solve(str, revStr, n, m - 1, dp));
    }
    int kPalindrome(string str, int n, int k)
    {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        string revStr = str;
        reverse(revStr.begin(), revStr.end());
        int ans = solve(str, revStr, n, n, dp);
        // cout << ans << endl;
        return (n - ans) <= k;
    }
};