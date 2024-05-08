// Function to find the data of nth node from the end of a linked list.
class Solution
{
public:
    int getNthFromLast(Node *head, int n)
    {
        // Your code here
        Node *node = head;
        while (n)
        {
            if (node == NULL && n)
                return -1;
            node = node->next;
            n--;
        }
        Node *temp = head;
        while (node != NULL)
        {
            node = node->next;
            temp = temp->next;
        }
        return temp->data;
    }
};
