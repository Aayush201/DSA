class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second < b.second)
            return true;
        else if (a.second > b.second)
            return false;
        else
            return a.first < b.first;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> tmp;
        for (int i = 0; i < n; i++)
            tmp.push_back({start[i], end[i]});
        sort(tmp.begin(), tmp.end(), cmp);
        int ans = 1, prev = tmp[0].second;
        for (int i = 1; i < n; i++)
        {
            // cout << tmp[i].first << " " << tmp[i].second << endl;
            if (tmp[i].first > prev)
            {
                ans++;
                prev = tmp[i].second;
            }
        }
        return ans;
    }
};