// Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return true;
            // if both the first and last element are equal to mid element
            // decrease the search space
            if (nums[mid] == nums[start] && nums[mid] == nums[end])
            {
                start++;
                end--;
            }
            else
            {
                // if left part is sorted
                if (nums[start] <= nums[mid])
                {
                    // if element is contained in the sorted part
                    if (nums[start] <= target && target <= nums[mid])
                        end = mid - 1;
                    else
                        start = mid + 1;
                }
                // if right part is sorted
                else
                {
                    // if element is contained in the sorted part
                    if (nums[mid] <= target && target <= nums[end])
                        start = mid + 1;
                    else
                        end = mid - 1;
                }
            }
        }
        return false;
    }
};