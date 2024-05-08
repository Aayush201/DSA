// Problem Link : https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

// Deletes middle of linked list and returns head of the modified list
class Solution
{
public:
    // Deletes middle of linked list and returns head of the modified list
    Node *deleteMid(Node *head)
    {
        // Your Code Here
        if (!head || (!head->next))
            return NULL;
        Node *slow = head, *fast = head->next;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *temp = slow->next;
        slow->next = temp->next;
        delete (temp);
        return head;
    }
};
