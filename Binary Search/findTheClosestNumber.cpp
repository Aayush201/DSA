// Problem Link : https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1

class Solution
{
public:
    int findClosest(int n, int k, int arr[])
    {
        // Complete the function
        int start = 0, end = n - 1;
        int flr = INT_MIN, cl = INT_MAX;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == k)
                return arr[mid];
            else if (arr[mid] < k)
            {
                flr = max(flr, arr[mid]);
                start = mid + 1;
            }
            else
            {
                cl = min(cl, arr[mid]);
                end = mid - 1;
            }
        }
        if (start == -1 || start == n)
            return arr[end];
        else
        {
            if (abs(k - arr[end]) < abs(k - arr[start]))
                return arr[end];
            else
                return arr[start];
        }
    }
};