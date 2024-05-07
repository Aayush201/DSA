class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int solve(Node *root, int &ans)
    {
        if (!root || !ans)
            return 0;
        if (!root->left && !root->right)
            return root->data;
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        if (root->data != (left + right))
        {
            ans = 0;
            return 0;
        }
        return left + right;
    }
    int isSumProperty(Node *root)
    {
        // Add your code here
        int ans = 1;
        solve(root, ans);
        return ans;
    }
};