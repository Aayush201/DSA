void solve(Node *root, vector<int> &ans)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *tmp = q.front();
        q.pop();
        while (tmp)
        {
            if (tmp->left)
                q.push(tmp->left);
            ans.push_back(tmp->data);
            tmp = tmp->right;
        }
    }
}

vector<int> diagonal(Node *root)
{
    // your code here
    vector<int> ans;
    solve(root, ans);
    return ans;
}