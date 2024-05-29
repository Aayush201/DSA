class Solution
{
public:
    int NumberofLIS(int n, vector<int> &arr)
    {
        // Code here
        vector<int> LISLength(n, 1);
        vector<int> countOfLIS(n, 1);
        int ans = 0, maxLength = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j += 1)
            {
                if (arr[i] > arr[j])
                {
                    if (1 + LISLength[j] > LISLength[i])
                    {
                        LISLength[i] = 1 + LISLength[j];
                        countOfLIS[i] = countOfLIS[j];
                    }
                    else if (1 + LISLength[j] == LISLength[i])
                        countOfLIS[i] += countOfLIS[j];
                }
            }
            maxLength = max(maxLength, LISLength[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (LISLength[i] == maxLength)
                ans += countOfLIS[i];
        }
        return ans;
    }
};