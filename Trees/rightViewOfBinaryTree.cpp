// Should return  right view of tree
class Solution
{
public:
    // Function to return list containing elements of right view of binary tree.
    void solve(Node *root, vector<int> &ans)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *tmp = q.front();
                q.pop();
                if (i == n - 1)
                    ans.push_back(tmp->data);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
        }
    }
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

