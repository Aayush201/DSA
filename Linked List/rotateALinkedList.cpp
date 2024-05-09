// Problem Link  : https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        // Your code here
        Node *tmp = head;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = head;
        tmp = head;
        while (--k)
        {
            tmp = tmp->next;
        }
        head = tmp->next;
        tmp->next = NULL;
        return head;
    }
};