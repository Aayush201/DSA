class Solution
{
public:
    vector<vector<int>> insertNewEvent(int n, vector<vector<int>> &intervals, vector<int> &newEvent)
    {
        // code here
        int i = 0;
        vector<vector<int>> ans;
        // pushing elements lesser than newEvent
        while (i < n && newEvent[0] > intervals[i][1])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        // merging intervals which are colliding with the newEvent
        while (i < n && newEvent[1] >= intervals[i][0])
        {
            newEvent[0] = min(newEvent[0], intervals[i][0]);
            newEvent[1] = max(newEvent[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newEvent);

        // finally push the remaining elements
        while (i < n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
