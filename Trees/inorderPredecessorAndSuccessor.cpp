class Solution
{
public:
    // Note : this question can be solved using the recursive methods while i have already done
    // along with the iterative ones.
    // This question purely uses the iterative method.
    void getPredecessor(Node *root, Node *&pre, int key)
    {
        while (root)
        {
            if (root->key >= key)
            {
                root = root->left;
            }
            else
            {
                pre = root;
                root = root->right;
            }
        }
    }
    void getSuccessor(Node *root, Node *&suc, int key)
    {
        while (root)
        {
            if (root->key <= key)
            {
                root = root->right;
            }
            else
            {
                suc = root;
                root = root->left;
            }
        }
    }
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        // Your code goes here
        getPredecessor(root, pre, key);
        getSuccessor(root, suc, key);
    }
};