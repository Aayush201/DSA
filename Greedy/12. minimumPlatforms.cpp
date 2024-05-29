class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        //  Brute force, for every train check how many trains are intersecting and get the
        //  maximum out of them

        // Better : Make another array using arrival time and departure time and then sort
        // that array. Finally if train is arriving increase the count and when train is
        // departing then decrease the count (At every step just get the maximum count)
        // final answer will be the maximum

        // Optimal : sorting arrival and departure arrays and then using two pointers on both
        // arrays and using the above increment and decrement method

        sort(arr, arr + n);
        sort(dep, dep + n);
        int ans = 0, count = 0, i = 0, j = 0;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};