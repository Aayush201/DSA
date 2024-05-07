class Solution
{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    void solveRecursive(Node *root, Node *x, Node *&successor)
    {
        if (!root)
            return;

        if (root->data <= x->data)
        {
            solveRecursive(root->right, x, successor);
        }
        else
        {
            successor = root;
            solveRecursive(root->left, x, successor);
        }
    }
    void solveIterative(Node *root, Node *x, Node *&successor)
    {
        while (root)
        {
            if (root->data <= x->data)
            {
                root = root->right;
            }
            else
            {
                successor = root;
                root = root->left;
            }
        }
    }
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        // Your code here
        Node *successor = NULL;
        // solveRecursive(root, x, successor);
        solveIterative(root, x, successor);
        return successor;
    }
};