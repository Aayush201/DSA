
class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    int solve(Node *root, int &ans)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        ans = max(1 + left + right, ans);
        return 1 + max(left, right);
    }
    int diameter(Node *root)
    {
        // Your code here
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};