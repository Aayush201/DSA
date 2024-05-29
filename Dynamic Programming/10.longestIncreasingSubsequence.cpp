class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    void solve(int index, int n, int *a, vector<int> &tmp)
    {
        if (index == n)
            return;
        int si = tmp.size();
        if (tmp[si - 1] < a[index])
            tmp.push_back(a[index]);
        else
        {
            int ind = lower_bound(tmp.begin(), tmp.end(), a[index]) - tmp.begin();
            tmp[ind] = a[index];
        }
        solve(index + 1, n, a, tmp);
    }
    int longestSubsequence(int n, int a[])
    {
        // your code here
        vector<int> tmp;
        tmp.push_back(a[0]);
        solve(1, n, a, tmp);
        return tmp.size();
    }
};