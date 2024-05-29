class Solution
{
public:
    int solve(int index, int n, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (index == n)
        {
            return amount == 0;
        }
        if (amount == 0)
            return 1;
        if (amount < 0)
            return 0;
        if (dp[index][amount] != -1)
            return dp[index][amount];
        int pick = 0, notPick = 0;
        // for(int i=index; i < n;i++){
        //     if(coins[i]<=amount)
        //         pick = solve(index,n,amount-coins[i],coins,dp);
        // }
        if (coins[index] <= amount)
            pick = solve(index, n, amount - coins[index], coins, dp);
        notPick = solve(index + 1, n, amount, coins, dp);
        return dp[index][amount] = pick + notPick;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return solve(0, n, amount, coins, dp);
    }
};