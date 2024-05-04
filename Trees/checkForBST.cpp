class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    void solve(Node *root, Node *&prev, bool &ans)
    {
        if (!root || !ans)
            return;
        solve(root->left, prev, ans);
        if (prev && prev->data >= root->data)
        {
            ans = false;
            return;
        }
        prev = root;
        solve(root->right, prev, ans);
    }
    bool isBST(Node *root)
    {
        // Your code here
        bool ans = true;
        Node *prev = NULL;
        solve(root, prev, ans);
        return ans;
    }
};