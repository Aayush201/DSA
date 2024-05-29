class Solution
{
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
    {
        // Code here
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (ans.back()[1] >= intervals[i][0])
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};