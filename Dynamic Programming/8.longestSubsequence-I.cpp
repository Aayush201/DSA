class Solution
{
public:
    int solve(vector<int> &a, vector<vector<int>> &dp, int prev, int index, int n)
    {
        if (index == n)
            return 0;
        if (dp[prev + 1][index] != -1)
            return dp[prev + 1][index];
        int pick = 0, notpick = 0;
        if (prev == -1)
        {
            pick = 1 + solve(a, dp, index, index + 1, n);
        }
        else if (abs(a[prev] - a[index]) == 1)
        {
            pick = 1 + solve(a, dp, index, index + 1, n);
        }
        notpick = solve(a, dp, prev, index + 1, n);
        return dp[prev + 1][index] = max(pick, notpick);
    }
    int longestSubseq(int n, vector<int> &a)
    {
        // code here
        // int prev = -1;
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(a,dp,prev,0,n);

        // using LIS approach
        vector<int> longestSub(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (abs(a[i] - a[j]) == 1)
                {
                    longestSub[i] = max(longestSub[i], 1 + longestSub[j]);
                }
            }
            ans = max(ans, longestSub[i]);
        }
        return ans;
    }
};