
class Solution
{
public:
    int solve(int index, int N, int W, int *val, int *wt, vector<int> &dp)
    {
        if (index >= N)
            return 0;
        if (W <= 0)
            return 0;
        if (dp[W] != -1)
            return dp[W];

        int pick = 0, notPick = 0;

        if (wt[index] <= W)
        {
            pick = val[index] + solve(index, N, W - wt[index], val, wt, dp);
        }
        notPick = solve(index + 1, N, W, val, wt, dp);
        return dp[W] = max(pick, notPick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W + 1, -1);
        return solve(0, N, W, val, wt, dp);
    }
};