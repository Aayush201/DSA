// Problem Link : https://www.naukri.com/code360/problems/delete-kth-node-from-end_799912?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *removeKthNode(Node *head, int k)
{
    // Write your code here.
    Node *tmp = head;
    k--;
    while (k--)
    {
        tmp = tmp->next;
    }
    Node *tmp2 = NULL;
    while (tmp && tmp->next)
    {
        tmp = tmp->next;
        if (tmp2 == NULL)
            tmp2 = head;
        else
            tmp2 = tmp2->next;
    }
    if (tmp2 == NULL)
    {
        head = head->next;
    }
    else
        tmp2->next = tmp2->next->next;
    return head;
}