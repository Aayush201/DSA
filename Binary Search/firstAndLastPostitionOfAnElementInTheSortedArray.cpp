
class Solution
{
public:
    int firstOccurrence(vector<int> &arr, int n, int x)
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
    int lastOccurrence(vector<int> &arr, int n, int x)
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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int first = firstOccurrence(nums, n, target);
        if (first == -1)
            return {-1, -1};
        int last = lastOccurrence(nums, n, target);
        // cout << first << " " << last << endl;
        return {first, last};
    }
};