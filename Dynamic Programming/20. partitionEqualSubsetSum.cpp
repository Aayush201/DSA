class Solution
{
public:
    char solve(int index, int sum, int N, int *arr, vector<char> &dp)
    {
        if (index == N)
        {
            if (sum == 0)
                return 'T';
            return 'F';
        }
        if (sum == 0)
            return 'T';
        if (sum < 0)
            return 'F';
        if (dp[sum] != '$')
        {
            return dp[sum];
        }
        int pick = 0, notpick = 0;
        if (arr[index] <= sum)
        {
            pick = solve(index + 1, sum - arr[index], N, arr, dp);
        }
        notpick = solve(index + 1, sum, N, arr, dp);
        if (pick == 'T' || notpick == 'T')
            dp[sum] = 'T';
        return dp[sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum % 2)
            return 0;
        vector<char> dp(sum / 2 + 1, '$');
        return solve(0, sum / 2, N, arr, dp) == 'T';
    }
};