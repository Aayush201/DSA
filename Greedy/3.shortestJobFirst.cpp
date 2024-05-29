class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        // code here
        sort(bt.begin(), bt.end());
        long long ans = 0, tat = 0;
        for (auto x : bt)
        {
            tat += 1ll * x;
            ans += tat - x;
        }
        return ans / bt.size();
    }
};