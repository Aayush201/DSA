// Problem Link : https://www.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1

class Solution
{
public:
    int find(int *arr, int N, int D, int mid)
    {
        int ans = 0, preSum = 0;
        for (int i = 0; i < N; i++)
        {
            preSum += arr[i];
            if (preSum == mid)
            {
                ans++;
                preSum = 0;
            }
            else if (preSum > mid)
            {
                preSum = arr[i];
                ans++;
            }
        }
        // cout << "Presum : " << preSum << endl;
        if (preSum != 0)
            ans++;
        if (ans <= D)
            return 1;
        return 0;
    }
    int leastWeightCapacity(int arr[], int N, int D)
    {
        // code here
        int start = 0, end = 0;
        for (int i = 0; i < N; i++)
        {
            start = max(start, arr[i]);
            end += arr[i];
        }
        int ans = end;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int isMidSufficient = find(arr, N, D, mid);
            if (isMidSufficient == 1)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};