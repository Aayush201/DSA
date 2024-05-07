bool isCousins(Node *root, int a, int b)
{
    // add code here.
    if (!root)
        return 0;
    queue<pair<Node *, Node *>> q;
    q.push({root, NULL});
    while (!q.empty())
    {
        int n = q.size(), founda = 0, foundb = 0;
        Node *f1, *f2;
        // cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            if (founda && foundb)
            {
                // cout <<"YES";
                break;
            }
            pair<Node *, Node *> p = q.front();
            q.pop();
            if (p.first->data == a)
            {
                founda = 1;
                f1 = p.second;
            }
            if (p.first->data == b)
            {
                foundb = 1;
                f2 = p.second;
            }
            if (p.first->left)
            {
                q.push({p.first->left, p.first});
            }
            if (p.first->right)
            {
                q.push({p.first->right, p.first});
            }
        }
        // cout << endl;
        if (founda && foundb && f1 != f2)
            return true;
    }
    return false;
}