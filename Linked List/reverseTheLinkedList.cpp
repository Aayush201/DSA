
class Solution
{
public:
    // Function to reverse a linked list.
    Node *reverseRecursive(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *newHead = reverseRecursive(head->next);
        Node *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    Node *reverseIterative(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        while (curr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    struct Node *reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list

        // head = reverseRecursive(head);

        head = reverseIterative(head);
        return head;
    }
};