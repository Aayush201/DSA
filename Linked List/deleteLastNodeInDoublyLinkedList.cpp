// Problem Link : https://www.naukri.com/code360/problems/delete-last-node-of-a-doubly-linked-list_8160469?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries

/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : data(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node *deleteLastNode(Node *head)
{
    // Write your code here
    Node *tmp = head;
    if (tmp->next == NULL)
        return NULL;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->prev->next = NULL;
    free(tmp);
    return head;
}
