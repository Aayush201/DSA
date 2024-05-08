// Problem Link : https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

class Solution
{
public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        // your code here
        if (head == NULL || head->next == NULL)
            return false;
        Node *slow = head;
        Node *fast = head;
        while (slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};