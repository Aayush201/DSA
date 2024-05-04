class Solution
{
public:
    void solve(Node *root, map<int, int> &mp, int verticalLevel)
    {
        if (!root)
            return;
        mp[verticalLevel] += root->data;
        solve(root->left, mp, verticalLevel - 1);
        solve(root->right, mp, verticalLevel + 1);
    }
    vector<int> verticalSum(Node *root)
    {
        // add code here.
        vector<int> ans;
        map<int, int> mp;
        solve(root, mp, 0);
        for (auto x : mp)
            ans.push_back(x.second);
        return ans;
    }
};