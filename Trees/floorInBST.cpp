class Solution
{

public:
    void solve(Node *root, int x, int &ans)
    {
        if (!root)
            return;
        if (root->data > x)
            solve(root->left, x, ans);
        else
        {
            ans = max(ans, root->data);
            solve(root->right, x, ans);
        }
    }
    int floor(Node *root, int x)
    {
        // Code here
        int ans = INT_MIN;
        solve(root, x, ans);
        return ans == INT_MIN ? -1 : ans;
    }
};
