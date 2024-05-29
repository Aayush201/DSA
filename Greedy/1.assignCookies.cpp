class Solution
{
public:
    int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz)
    {
        // code here
        sort(greed.begin(), greed.end());
        sort(sz.begin(), sz.end());
        int ans = 0;
        int i = 0, j = 0;
        while (i < N && j < M)
        {
            if (greed[i] <= sz[j])
            {
                ans += 1;
                i++;
                j++;
            }
            else if (greed[i] > sz[j])
                j++;
        }
        return ans;
    }
};