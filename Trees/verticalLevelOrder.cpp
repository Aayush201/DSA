class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    void solve(Node *root, map<int, vector<int>> &mp, int verticalLev)
    {
        queue<pair<Node *, int>> q;
        q.push({root, verticalLev});
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *tmp = q.front().first;
                int verticalLevel = q.front().second;
                q.pop();
                mp[verticalLevel].push_back(tmp->data);
                if (tmp->left)
                    q.push({tmp->left, verticalLevel - 1});
                if (tmp->right)
                    q.push({tmp->right, verticalLevel + 1});
            }
        }
    }
    vector<int> verticalOrder(Node *root)
    {
        // Your code here
        vector<int> ans;
        map<int, vector<int>> mp;
        solve(root, mp, 0);
        for (auto x : mp)
            for (auto val : x.second)
                ans.push_back(val);
        return ans;
    }
};