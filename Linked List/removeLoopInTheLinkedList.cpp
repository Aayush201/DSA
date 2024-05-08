// Problem Link : https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *slow = head, *fast = head;
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (slow != fast)
            return;
        slow = head;
        // finding the starting node of the loop
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        // traversing again to point to the node just before the starting node of the loop
        Node *start = slow;
        while (start->next != slow)
        {
            start = start->next;
        }
        start->next = NULL;
    }
};