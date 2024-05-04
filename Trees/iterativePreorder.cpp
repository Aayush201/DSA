class Solution
{
public:
    void solve(Node *root, vector<int> &ans)
    {
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *tmp = st.top();
            st.pop();
            ans.push_back(tmp->data);
            if (tmp->right)
                st.push(tmp->right);
            if (tmp->left)
                st.push(tmp->left);
        }
    }
    vector<int> preOrder(Node *root)
    {
        // code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

