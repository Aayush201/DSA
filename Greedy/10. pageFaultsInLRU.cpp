class Solution
{
public:
    int pageFaults(int N, int C, int pages[])
    {
        // code here
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            if (mp.size() < C)
            {
                if (mp.find(pages[i]) == mp.end())
                {
                    ans++;
                    mp[pages[i]] = i + 1;
                }
                else
                    mp[pages[i]] = i + 1;
            }
            else
            {
                if (mp.find(pages[i]) != mp.end())
                {
                    mp[pages[i]] = i + 1;
                }
                else
                {
                    int minElement = INT_MAX, minIndex = INT_MAX;
                    for (auto x : mp)
                    {
                        if (x.second < minIndex)
                        {
                            minIndex = x.second;
                            minElement = x.first;
                        }
                    }
                    mp.erase(minElement);
                    ans++;
                    mp[pages[i]] = i + 1;
                }
            }
        }
        return ans;
    }
};