class Solution
{
public:
    void solve(Node *root, vector<int> &ans)
    {
        stack<pair<Node *, int>> st;
        st.push({root, 0});
        while (!st.empty())
        {
            Node *tmp = st.top().first;
            int flag = st.top().second;
            if (flag)
                ans.push_back(tmp->data);
            st.pop();
            if (tmp->right && !flag)
                st.push({tmp->right, 0});
            if (!flag)
                st.push({tmp, 1});
            if (tmp->left && !flag)
                st.push({tmp->left, 0});
        }
    }
    vector<int> inOrder(Node *root)
    {
        // code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};