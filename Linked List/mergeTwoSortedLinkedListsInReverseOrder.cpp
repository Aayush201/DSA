// Problem Link : https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1

/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
public:
    struct Node *mergeResult(Node *node1, Node *node2)
    {
        // your code goes here
        Node *tmp1 = node1, *tmp2 = node2;
        Node *newHead = NULL;
        while (tmp1 && tmp2)
        {
            if (tmp1->data < tmp2->data)
            {
                Node *prev = tmp1;
                tmp1 = tmp1->next;
                if (newHead == NULL)
                {
                    newHead = prev;
                    newHead->next = NULL;
                }
                else
                {
                    prev->next = newHead;
                    newHead = prev;
                }
            }
            else
            {
                Node *prev = tmp2;
                tmp2 = tmp2->next;
                if (newHead == NULL)
                {
                    newHead = prev;
                    newHead->next = NULL;
                }
                else
                {
                    prev->next = newHead;
                    newHead = prev;
                }
            }
        }
        while (tmp1)
        {
            Node *prev = tmp1;
            tmp1 = tmp1->next;
            if (newHead == NULL)
            {
                newHead = prev;
                newHead->next = NULL;
            }
            else
            {
                prev->next = newHead;
                newHead = prev;
            }
        }
        while (tmp2)
        {
            Node *prev = tmp2;
            tmp2 = tmp2->next;
            if (newHead == NULL)
            {
                newHead = prev;
                newHead->next = NULL;
            }
            else
            {
                prev->next = newHead;
                newHead = prev;
            }
        }

        return newHead;
    }
};