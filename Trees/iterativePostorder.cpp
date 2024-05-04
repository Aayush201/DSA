class Solution
{
public:
    // Method 1
    void solve(Node *root, vector<int> &ans)
    {
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *tmp = st.top();
            st.pop();
            ans.push_back(tmp->data);
            if (tmp->left)
                st.push(tmp->left);
            if (tmp->right)
                st.push(tmp->right);
        }
        reverse(ans.begin(), ans.end());
    }
    // Method 2 using flag
    /*
        class Solution{
    public:
    vector<int> postOrder(Node* root) {
        // code here
        stack<pair<Node*, int>>st;
        vector<int>ans;
        st.push({root,0});

        while(!st.empty()){
            pair<Node*, int> p = st.top();
            st.pop();
            if(!p.second){
                st.push({p.first,1});
                if(p.first->right){ st.push({p.first->right,0});}
                if(p.first->left){ st.push({p.first->left,0});}
            }
            else{
                ans.push_back(p.first->data);
            }
        }
        return ans;
    }
;}
    */
    vector<int> postOrder(Node *root)
    {
        // code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};