#define mod 1000000007
class Solution
{

public:
    int solve(int arr[], int index, int n, int sum, vector<vector<int>> &dp)
    {
        if (index == n)
        {
            return sum == 0;
        }
        if (sum < 0)
            return 0;
        if (dp[index][sum] != -1)
            return dp[index][sum] % mod;

        return dp[index][sum] = ((solve(arr, index + 1, n, sum - arr[index], dp) % mod) +
                                 (solve(arr, index + 1, n, sum, dp) % mod));
    }
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(arr, 0, n, sum, dp) % mod;
    }
};