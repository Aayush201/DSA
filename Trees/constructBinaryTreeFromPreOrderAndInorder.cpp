
class Solution
{
public:
    Node *treeBuilder(map<int, queue<int>> &mp, int *in, int inStart, int inEnd, int *pre, int preStart, int preEnd)
    {
        if (inStart > inEnd || preStart > preEnd)
            return NULL;
        Node *newNode = new Node(pre[preStart]);
        int inIndex = mp[pre[preStart]].front();
        mp[pre[preStart]].pop();
        int totalNumbers = inIndex - inStart;
        newNode->left = treeBuilder(mp, in, inStart, inIndex - 1, pre, preStart + 1, preStart + totalNumbers);
        newNode->right = treeBuilder(mp, in, inIndex + 1, inEnd, pre, preStart + totalNumbers + 1, preEnd);
        return newNode;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        map<int, queue<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[in[i]].push(i);
        }
        Node *root = treeBuilder(mp, in, 0, n - 1, pre, 0, n - 1);
        return root;
    }
};
