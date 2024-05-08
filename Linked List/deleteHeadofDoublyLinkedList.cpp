// Problem Link : https://www.naukri.com/code360/problems/insert-before-the-given-node-of-a-doubly-linked-list_9719100?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev=NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->next= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};
*/

Node *deleteHead(Node *head)
{
    // Write your code here.
    if (!head || !head->next)
    {
        free(head);
        return NULL;
    }
    Node *tmp = head;
    head = head->next;
    head->prev = NULL;
    free(tmp);
    return head;
}
