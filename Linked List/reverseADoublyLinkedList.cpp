// Problem Link : https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

class Solution
{
public:
    Node *reverseDLL(Node *head)
    {
        // Your code here
        if (!head || !head->next)
            return head;
        Node *curr = head, *pre = NULL, *nxt = head->next;
        while (nxt)
        {
            curr->next = pre;
            curr->prev = nxt;
            pre = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        curr->next = pre;
        curr->prev = nxt;
        head = curr;
        return head;
    }
};