
class Solution
{
public:
    // return true/false denoting whether the tree is Symmetric or not
    bool solve(Node *root1, Node *root2)
    {
        if (!root1 && !root2)
            return true;
        if (!root1 && root2)
            return false;
        if (root1 && !root2)
            return false;
        if (root1->data != root2->data)
            return false;
        if (root1 && root2)
        {
            return solve(root1->left, root2->right) && solve(root1->right, root2->left);
        }
    }
    bool isSymmetric(struct Node *root)
    {
        // Code here
        return solve(root, root);
    }
};