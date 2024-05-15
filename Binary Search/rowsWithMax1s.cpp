// Problem Link : https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

// User function template for C++
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        // code here
        int ans = -1, i = 0, j = m - 1;
        while (i < arr.size() && j >= 0)
        {
            if (arr[i][j] == 1)
            {
                ans = i;
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
