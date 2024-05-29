class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[1] < b[1])
            return true;
        else if (a[1] > b[1])
            return false;
        return a[0] < b[0];
    }
    int minRemoval(int N, vector<vector<int>> &intervals)
    {
        // code here
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0;
        int prev = intervals[0][1];
        for (int i = 1; i < N; i++)
        {
            if (intervals[i][0] < prev)
                ans++;
            else
                prev = intervals[i][1];
        }
        return ans;
    }
};