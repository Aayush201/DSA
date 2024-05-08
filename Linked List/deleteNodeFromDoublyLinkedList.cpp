// Problem link : https://www.naukri.com/code360/problems/non-head-node-deletion_9719173?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries

Following is the linkedList class structure :

    class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->data = val;
        next = NULL;
        prev = NULL;
    }
};

************************************************************ /

    void deleteNode(Node *node)
{
    // Write your code here.
    node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;
    free(node);
}