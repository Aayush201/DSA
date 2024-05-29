// Problem Link : https://www.geeksforgeeks.org/problems/count-the-zeros2550/1

class Solution
{
public:
    int countZeroes(int arr[], int n)
    {
        // code here
        int ans = -1;
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == 0)
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        if (ans == -1)
            return 0;
        return n - start;
    }
};