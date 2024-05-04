class Solution
{
public:
    void solve(Node *root, int &K, int &ans)
    {
        if (!root || !K)
            return;
        solve(root->right, K, ans);
        K--;
        if (!K)
        {
            ans = root->data;
            return;
        }
        solve(root->left, K, ans);
    }
    int kthLargest(Node *root, int K)
    {
        // Your code here
        int ans = -1;
        solve(root, K, ans);
        return ans;
    }
};