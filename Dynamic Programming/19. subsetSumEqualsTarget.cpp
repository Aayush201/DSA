class Solution
{
public:
    bool calc(vector<vector<int>> &dp, vector<int> &arr, int sum, int n)
    {
        // n to zero
        if (sum == 0)
            return true;
        if (n == 0 || sum < 0)
            return false;
        if (dp[n][sum] != -1)
            return dp[n][sum];
        if (sum - arr[n - 1] < 0)
        {
            return dp[n][sum] = calc(dp, arr, sum, n - 1);
        }
        else
        {
            return dp[n][sum] = calc(dp, arr, sum - arr[n - 1], n - 1) || calc(dp, arr, sum, n - 1);
        }
    }
    bool solve(vector<vector<int>> &dp, vector<int> &arr, int val, int sum, int index, int n)
    {
        // zero to n
        if (val == sum)
            return 1;
        if (index == n || val > sum)
            return 0;
        if (dp[index][val] != -1)
            return dp[index][val];
        if (val + arr[index] > sum)
        {
            dp[index][val] = solve(dp, arr, val, sum, index + 1, n);
        }
        else
        {
            dp[index][val] = solve(dp, arr, val + arr[index], sum, index + 1, n) || solve(dp, arr, val, sum, index + 1, n);
        }
        return dp[index][val];
    }
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = n; i >= 0; i--)
        {
            for (int j = sum; j >= 0; j--)
            {
                if (j == sum)
                    dp[i][j] = 1;
                else if (i == n)
                    dp[i][j] = 0;
                else if (arr[i] + j > sum)
                {
                    dp[i][j] = dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = dp[i + 1][j] || dp[i + 1][j + arr[i]];
                }
            }
        }
        // for(int i = 0 ; i <=n;i++){
        //     for(int j = 0 ; j <= sum ;j++){
        //         if(i == 0 && j == 0) dp[i][j] = 1;
        //         else if(i == 0) dp[i][j] = 0;
        //         else if(j == 0) dp[i][j] = 1;
        //         else if(j-arr[i-1] < 0){
        //             dp[i][j] = dp[i-1][j];
        //         }
        //         else{
        //             dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
        //         }
        //     }
        // }
        // for(auto x : dp){

        //     for(auto val : x)
        //         cout << val << " ";
        //     cout << endl;
        // }
        // return calc(dp,arr,sum,n);
        // return dp[n][sum];
        // return solve(dp,arr,0,sum,0,n);
        return dp[0][0];
    }
};