// Problem Link : https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */

    // Note this question can be solved using the lower bound and upper bound as well
    int usingLowerAndUpperBound(int *arr, int n, int x)
    {
        int ans = -1;
        int lower = lower_bound(arr, arr + n, x) - arr;
        if (arr[lower] != x)
            return 0;
        int upper = upper_bound(arr, arr + n, x) - arr;
        return upper - lower;
    }
    int firstOccurrence(int *arr, int n, int x)
    {
        int ans = -1;
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x)
            {
                ans = mid;
                end = mid - 1;
            }
            else if (arr[mid] < x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
    int lastOccurrence(int *arr, int n, int x)
    {
        int ans = -1;
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x)
            {
                ans = mid;
                start = mid + 1;
            }
            else if (arr[mid] < x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
    int count(int arr[], int n, int x)
    {
        // return usingLowerAndUpperBound(arr,n,x);
        int first = firstOccurrence(arr, n, x);
        if (first == -1)
            return 0;
        int last = lastOccurrence(arr, n, x);
        // cout << first << " " << last << endl;
        return last - first + 1;
    }
};