class Solution
{
public:
    const int mod = 1e9 + 7;
    int solve(int n, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (n == 0)
            return sum == 0;
        if (sum < 0)
            return 0;
        if (dp[n][sum] != -1)
            return dp[n][sum];
        if (arr[n - 1] <= sum)
        {
            dp[n][sum] = (solve(n - 1, sum - arr[n - 1], arr, dp) + solve(n - 1, sum, arr, dp)) % mod;
        }
        else
        {
            dp[n][sum] = solve(n - 1, sum, arr, dp) % mod;
        }
        return dp[n][sum] % mod;
    }
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int sum = 0;
        for (auto x : arr)
            sum += x;
        if (sum - d < 0 || (sum - d) % 2)
            return 0;
        sum = (sum - d) / 2;
        // vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        // return solve(n,sum,arr,dp);


        // Tabulation : 
        // vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j <= sum; j++)
        //     {
        //         if (i == 0)
        //         {
        //             if (j == 0)
        //                 dp[i][j] = 1;
        //             else
        //                 dp[i][j] = 0;
        //         }
        //         else if (arr[i - 1] <= j)
        //         {
        //             dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;
        //         }
        //         else
        //         {
        //             dp[i][j] = dp[i - 1][j] % mod;
        //         }
        //     }
        // }
        // return dp[n][sum];

        // Space optimized
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0)
                {
                    if (j == 0)
                        curr[j] = 1;
                    else
                        curr[j] = 0;
                }
                else if (arr[i - 1] <= j)
                {
                    curr[j] = (prev[j - arr[i - 1]] + prev[j]) % mod;
                }
                else
                {
                    curr[j] = prev[j] % mod;
                }
            }
            prev = curr;
        }
        return prev[sum];
    }
};