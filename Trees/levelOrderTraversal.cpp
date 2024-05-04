class Solution
{
public:
    // Function to return the level order traversal of a tree.
    void solve(Node *root, vector<int> &ans)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *temp = q.front();
                q.pop();
                ans.push_back(temp->data);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
    }
    vector<int> levelOrder(Node *root)
    {
        // Your code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};