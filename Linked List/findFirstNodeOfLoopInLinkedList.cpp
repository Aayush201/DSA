// Problem Link : https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

class Solution
{
public:
    // Function to find first node if the linked list has a loop.
    int findFirstNode(Node *head)
    {
        Node *slow = head, *fast = head;
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (slow != fast)
            return -1;
        Node *tmp = head;
        while (tmp != slow)
        {
            slow = slow->next;
            tmp = tmp->next;
        }
        return slow->data;
    }
};