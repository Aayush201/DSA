// Problem Link : https://www.geeksforgeeks.org/problems/insert-in-sorted-way-in-a-sorted-dll/1

/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
Node *sortedInsert(Node *head, int x)
{
    // Code here
    Node *tmp = head;
    Node *newNode = getNode(x);
    Node *tail = NULL;
    while (tmp && tmp->data < x)
    {
        if (tmp->next == NULL)
        {
            tail = tmp;
        }
        tmp = tmp->next;
    }
    if (tmp == head)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if (tmp == NULL)
    {
        newNode->prev = tail;
        tail->next = newNode;
    }
    else
    {
        newNode->next = tmp;
        newNode->prev = tmp->prev;
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
    }
    return head;
};