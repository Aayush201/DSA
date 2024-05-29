// Problem Link : https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

class Solution
{
public:
    int isMidPossible(long double mid, vector<int> &stations)
    {
        int count = 0;
        for (int i = 0; i < stations.size() - 1; i++)
        {
            long double diff = (long double)(stations[i + 1] - stations[i]);
            int tmp = diff / mid;
            if ((long double)diff / mid == (long double)tmp * mid)
                tmp--;
            count += tmp;
        }
        return count;
    }
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        // Code here
        long double start = 0, end = 0;
        for (int i = 0; i < stations.size() - 1; i++)
        {
            end = max(end, (long double)(stations[i + 1] - stations[i]));
        }
        long double ans = end;
        long double diff = 1e-6;
        while ((end - start) > diff)
        {
            long double mid = start + (end - start) / 2.0;
            int val = isMidPossible(mid, stations);
            if (val > k)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        return end;
    }
};