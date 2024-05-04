class Solution
{
public:
    void solve(Node *root, map<int, int> &mp, int val)
    {
        queue<pair<Node *, int>> q;
        q.push({root, val});
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *tmp = q.front().first;
                int verticalLev = q.front().second;
                q.pop();
                mp[verticalLev] = tmp->data;
                if (tmp->left)
                    q.push({tmp->left, verticalLev - 1});
                if (tmp->right)
                    q.push({tmp->right, verticalLev + 1});
            }
        }
    }
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        vector<int> ans;
        map<int, int> mp;
        solve(root, mp, 0);
        for (auto x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};