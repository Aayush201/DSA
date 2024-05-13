// Problem Link : https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1

class Solution
{
public:
    int find(vector<int> &bloomDay, long long mid, long long M, long long K)
    {
        long long count = 0, ans = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (1ll * bloomDay[i] <= mid)
            {
                count++;
                if (count % K == 0)
                {
                    ans++;
                    count = 0;
                }
            }
            else
            {
                count = 0;
            }
            if (ans >= M)
                return 1;
        }
        return 0;
    }
    int solve(int M, int K, vector<int> &bloomDay)
    {
        long long start = INT_MAX, end = INT_MIN;
        long long ans = -1;
        for (auto x : bloomDay)
        {
            start = min(start, 1ll * x);
            end = max(end, 1ll * x);
        }
        //   cout << start << " " << end << endl;
        while (start <= end)
        {
            long long mid = start + (end - start) / 2;
            int canWeFind = find(bloomDay, mid, M, K);
            //   cout << mid << endl;
            if (canWeFind == 1)
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
