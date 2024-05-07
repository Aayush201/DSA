vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *tmp = q.front();
            q.pop();
            ans.push_back(tmp->data);
            if (tmp->right)
                q.push(tmp->right);
            if (tmp->left)
                q.push(tmp->left);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}