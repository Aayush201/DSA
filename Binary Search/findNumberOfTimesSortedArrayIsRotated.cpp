// Problem Link : https://geeksforgeeks.org/problems/rotation4723/1

class Solution
{
public:
    int findKRotation(int arr[], int n)
    {
        // code here
        int ans = INT_MAX, index = -1;
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            // left part is sorted
            if (arr[start] <= arr[mid])
            {
                if (ans > arr[start])
                {
                    ans = arr[start];
                    index = start;
                }
                start = mid + 1;
            }
            // right part is sorted
            else
            {
                if (ans > arr[mid])
                {
                    ans = arr[mid];
                    index = mid;
                }
                end = mid - 1;
            }
        }
        // cout << ans << endl;
        return index;
    }
};