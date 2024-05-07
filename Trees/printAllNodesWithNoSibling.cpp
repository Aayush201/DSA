void findNodesWithNoSiblings(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        return;
    }
    if (!root->left && root->right)
        ans.push_back(root->right->data);
    else if (root->left && !root->right)
        ans.push_back(root->left->data);
    findNodesWithNoSiblings(root->left, ans);
    findNodesWithNoSiblings(root->right, ans);
}
vector<int> noSibling(Node *node)
{
    // code here
    vector<int> ans;
    findNodesWithNoSiblings(node, ans);
    sort(ans.begin(), ans.end());
    if (ans.size() == 0)
        ans = {-1};
    return ans;
}