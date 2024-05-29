class Solution
{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> ans;
        vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        for (auto x : denominations)
        {
            while (N >= x)
            {
                N -= x;
                ans.push_back(x);
            }
        }
        return ans;
    }
};