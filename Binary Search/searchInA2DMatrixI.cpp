// Problem Link : https://leetcode.com/problems/search-a-2d-matrix/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int start = 0, end = n * m - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target)
                return true;
            if (matrix[row][col] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};