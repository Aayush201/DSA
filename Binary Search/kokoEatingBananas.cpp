// Problem Link : https://www.geeksforgeeks.org/problems/koko-eating-bananas/1

class Solution
{
public:
    int find(vector<int> &piles, int mid)
    {
        int count = 0;
        for (auto x : piles)
        {
            count += ceil((double)x / mid);
        }
        return count;
    }
    int Solve(int N, vector<int> &piles, int H)
    {
        // Code here
        int start = 1, end = 1;
        int ans = 0;
        for (auto x : piles)
            end = max(end, x);
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int countHrs = find(piles, mid);
            if (countHrs <= H)
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};