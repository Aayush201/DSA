// Problem Link : https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

class Solution
{
public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        if (!head)
            return NULL;
        Node *slow = head, *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
    }
};