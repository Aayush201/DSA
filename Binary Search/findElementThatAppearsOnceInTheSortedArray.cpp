// Problem Link : https://geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1

class Solution
{
public:
    int findOnce(int arr[], int n)
    {
        // code here.
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid == 0 && arr[mid + 1] != arr[mid])
                return arr[mid];
            if (mid == n - 1 && arr[mid - 1] != arr[mid])
                return arr[mid];
            if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1])
                return arr[mid];
            if (mid % 2 != 0)
            {
                if (arr[mid] == arr[mid - 1])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else
            {
                if (arr[mid] == arr[mid - 1])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
    }
};