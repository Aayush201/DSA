
// Function to search a node in BST.
bool search(Node *root, int k)
{
    // Your code here
    if (!root)
        return false;
    if (root->data == k)
        return true;
    if (root->data < k)
        return search(root->right, k);
    else
        return search(root->left, k);
}
