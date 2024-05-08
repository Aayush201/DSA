// Problem Link : https://www.naukri.com/code360/problems/insert-at-the-front-of-a-doubly-linked-list_9697366?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

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

Node *insertAtFront(Node *head, int k)
{
    // Write your code here.
    Node *newNode = new Node(k);
    if (head == NULL)
        return newNode;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}