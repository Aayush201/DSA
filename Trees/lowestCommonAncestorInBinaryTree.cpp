class Solution
{
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node *solve(Node *root, int n1, int n2)
    {
        if (!root || root->data == n1 || root->data == n2)
            return root;
        Node *l = solve(root->left, n1, n2);
        Node *r = solve(root->right, n1, n2);
        if (!l)
            return r;
        if (!r)
            return l;
        return root;
    }
    Node *lca(Node *root, int n1, int n2)
    {
        // Your code here
        return solve(root, n1, n2);
    }
};