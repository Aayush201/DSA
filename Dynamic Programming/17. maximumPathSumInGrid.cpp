class Solution
{
public:
    int dp[1001][1001];
    int solve(int i, int j, int row, int col, vector<vector<int>> &matrix)
    {
        if (i >= row || j < 0 || j >= col)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int p = matrix[i][j] + solve(i + 1, j, row, col, matrix);
        int q = matrix[i][j] + solve(i + 1, j - 1, row, col, matrix);
        int r = matrix[i][j] + solve(i + 1, j + 1, row, col, matrix);
        return dp[i][j] = max({p, q, r});
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        int ans = INT_MIN;
        for (int i = 0; i < N; i++)
        {
            ans = max(ans, solve(0, i, N, N, Matrix));
        }
        return ans;
    }
};