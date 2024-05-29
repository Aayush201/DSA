
int longestPalinSubseq(string S)
{
    // your code here
    string ok = S;
    reverse(ok.begin(), ok.end());
    int dp[S.length() + 1][S.length() + 1];

    for (int i = 0; i < S.length() + 1; i++)
        for (int j = 0; j < S.length() + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i <= S.length(); i++)
    {
        for (int j = 1; j <= S.length(); j++)
        {
            if (S[i - 1] == ok[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[S.length()][S.length()];
}