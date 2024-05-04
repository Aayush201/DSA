class Solution
{
public:
    // Function to return a tree created from postorder and inoreder traversals.
    Node *treeBuilder(map<int, int> &mp, int *in, int inStart, int inEnd, int *post, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd)
            return NULL;
        Node *newNode = new Node(post[postEnd]);
        int inIndex = mp[newNode->data];
        int totalNumbers = inEnd - inIndex;
        Node *left = treeBuilder(mp, in, inStart, inIndex - 1, post, postStart, postEnd - totalNumbers - 1);
        Node *right = treeBuilder(mp, in, inIndex + 1, inEnd, post, postEnd - totalNumbers, postEnd - 1);
        newNode->left = left;
        newNode->right = right;
        return newNode;
    }
    Node *buildTree(int in[], int post[], int n)
    {
        // Your code here
        map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[in[i]] = i;
        Node *root = treeBuilder(mp, in, 0, n - 1, post, 0, n - 1);
        return root;
    }
};