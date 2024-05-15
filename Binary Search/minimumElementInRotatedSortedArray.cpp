// Problem Link : https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1

class Solution
{
public:
    int findMin(int arr[], int n)
    {
        // complete the function here
        int start = 0, end = n - 1;
        int ans = INT_MAX;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            // left part is sorted pick minimum from it and move to right
            if (arr[start] <= arr[mid])
            {
                ans = min(arr[start], ans);
                start = mid + 1;
            }
            // if right part is sorted pick minimum from it and move to left
            else
            {
                ans = min(arr[mid], ans);
                end = mid - 1;
            }
        }
        return ans;
    }
};