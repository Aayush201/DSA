class Solution
{
public:
    vector<int> LargestSubset(int n, vector<int> &arr)
    {
        // Code here
        sort(arr.begin(), arr.end());
        vector<int> LDS(n, 1);
        vector<int> indices(n, 0);
        int maxLDS = 0, index = 0;
        for (int i = 0; i < n; i++)
            indices[i] = i;

        for (int i = 1; i < n; i += 1)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0 && 1 + LDS[j] > LDS[i])
                {
                    LDS[i] = 1 + LDS[j];
                    indices[i] = j;
                }
            }
            if (LDS[i] > maxLDS)
            {
                maxLDS = LDS[i];
                index = i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[index]);
        while (indices[index] != index)
        {
            ans.push_back(arr[indices[index]]);
            index = indices[index];
        }
        reverse(ans.begin(), ans.end());
        // for(auto x: ans)cout << x << endl;
        return ans;
    }
};