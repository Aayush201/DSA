class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        // Code here
        vector<int> LISLength(n, 1);
        vector<int> getLIS(n);
        for (int i = 0; i < n; i++)
        {
            getLIS[i] = i;
        }
        vector<int> ans;
        int index = 0, maxLength = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                if (arr[i] > arr[j] && 1 + LISLength[j] > LISLength[i])
                {
                    LISLength[i] = 1 + LISLength[j];
                    getLIS[i] = j;
                }
            }
            if (LISLength[i] > maxLength)
            {
                maxLength = LISLength[i];
                index = i;
            }
        }
        // for(auto x : LISLength) cout << x << " ";
        // cout << endl;
        // for(auto x : getLIS) cout << x << " ";
        // cout << endl;
        ans.push_back(arr[index]);
        while (index != getLIS[index])
        {
            ans.push_back(arr[getLIS[index]]);
            index = getLIS[index];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};