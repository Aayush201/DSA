// Problem Link : https://www.naukri.com/code360/problems/insert-at-end-of-doubly-linked-list_8160464?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries

/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node *insertAtTail(Node *head, int k)
{
    // Write your code here
    Node *newNode = new Node(k);
    if (head == NULL)
        return newNode;
    Node *tmp = head;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    newNode->prev = tmp;
    tmp->next = newNode;
    return head;
}
