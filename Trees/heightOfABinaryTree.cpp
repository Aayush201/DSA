class Solution
{
public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        // code here
        if (!node)
            return 0;
        if (!node->left && !node->right)
            return 1;
        int left = height(node->left);
        int right = height(node->right);
        return 1 + max(left, right);
    }
};