class Solution
{
public:
    void solve(Node *root, int data)
    {
        if (!root)
            return;
        if (root->data > data)
        {
            if (!root->left)
            {
                Node *newNode = new Node(data);
                root->left = newNode;
                return;
            }
            solve(root->left, data);
        }
        else if (root->data < data)
        {
            if (!root->right)
            {
                Node *newNode = new Node(data);
                root->right = newNode;
                return;
            }
            solve(root->right, data);
        }
    }
    Node *insert(Node *node, int data)
    {
        solve(node, data);
        return node;
    }
};