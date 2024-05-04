// Function to return the ceil of given number in BST.
void solve(Node *root, int input, int &ans)
{
    if (!root)
        return;
    if (root->data < input)
    {
        solve(root->right, input, ans);
    }
    else
    {
        ans = min(ans, root->data);
        solve(root->left, input, ans);
    }
}
int findCeil(Node *root, int input)
{
    int ans = INT_MAX;
    solve(root, input, ans);
    return ans == INT_MAX ? -1 : ans;
}