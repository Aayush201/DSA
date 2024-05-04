class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.
    int solve(Node *root, bool &balanced)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        if (!balanced)
            return 0;
        int left = solve(root->left, balanced);
        int right = solve(root->right, balanced);
        if (abs(left - right) > 1)
            balanced = false;
        return 1 + max(left, right);
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        bool balanced = true;
        solve(root, balanced);
        return balanced;
    }
};
