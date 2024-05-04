class Solution
{
public:
    void solve(Node *root, vector<vector<int>> &ans, vector<int> &tmp)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            tmp.push_back(root->data);
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }
        tmp.push_back(root->data);
        solve(root->left, ans, tmp);
        solve(root->right, ans, tmp);
        tmp.pop_back();
    }
    vector<vector<int>> Paths(Node *root)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(root, ans, tmp);
        return ans;
    }
};