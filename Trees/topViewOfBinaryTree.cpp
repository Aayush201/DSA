class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    void solve(Node *root, map<int, int> &mp, int val)
    {
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *tmp = q.front().first;
                int verticalLev = q.front().second;
                q.pop();
                if (mp.find(verticalLev) == mp.end())
                {
                    mp[verticalLev] = tmp->data;
                }
                if (tmp->left)
                    q.push({tmp->left, verticalLev - 1});
                if (tmp->right)
                    q.push({tmp->right, verticalLev + 1});
            }
        }
    }
    vector<int> topView(Node *root)
    {
        // Your code here
        vector<int> ans;
        map<int, int> mp;
        solve(root, mp, 0);
        for (auto x : mp)
            ans.push_back(x.second);
        return ans;
    }
};
