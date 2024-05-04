
class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    void solve(Node *root, vector<int> &ans)
    {
        queue<Node *> q;
        q.push(root);
        int flag = 1;
        while (!q.empty())
        {
            vector<int> tmp;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *n = q.front();
                q.pop();
                tmp.push_back(n->data);
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
            if (flag)
            {
                for (int i = 0; i < n; i++)
                    ans.push_back(tmp[i]);
            }
            else
            {
                for (int i = n - 1; i >= 0; i--)
                    ans.push_back(tmp[i]);
            }
            flag = !flag;
        }
    }
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};