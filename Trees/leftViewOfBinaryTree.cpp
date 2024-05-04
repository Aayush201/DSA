void solve(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        Node *tmp;
        for (int i = 0; i < n; i++)
        {
            tmp = q.front();
            q.pop();
            if (i == 0)
                ans.push_back(tmp->data);
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
    }
}
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    solve(root, ans);
    return ans;
}