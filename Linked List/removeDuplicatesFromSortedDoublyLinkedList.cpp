// Problem Link : https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        // Your code here
        Node *tmp = head;
        while (tmp)
        {
            Node *nxt = tmp->next;
            while (nxt && nxt->data == tmp->data)
            {
                Node *tmp1 = nxt;
                nxt = nxt->next;
                free(tmp1);
            }
            tmp->next = nxt;
            if (nxt)
                nxt->prev = tmp;
            tmp = tmp->next;
        }
        return head;
    }
};
