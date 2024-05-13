// Problem Link : https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find

    // I am also writing the function for ceil in sorted array
    int findCeil(vector<long long> arr, long long n, long long x)
    {
        int ans = -1;
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x)
                return mid;
            else if (arr[mid] > x)
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
    int findFloor(vector<long long> arr, long long n, long long x)
    {
        // cout << "Ceil : " << findCeil(arr,n,x) << endl;
        int ans = -1;
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x)
                return mid;
            else if (arr[mid] < x)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};