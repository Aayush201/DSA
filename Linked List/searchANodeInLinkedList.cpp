class Solution
{
public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node *head, int key)
    {
        // Code here
        Node *tmp = head;
        while (tmp)
        {
            if (tmp->data == key)
                return true;
            tmp = tmp->next;
        }
        return false;
    }
};