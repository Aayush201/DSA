// Problem Link : https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

/* Link list Node

    struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/

    /*You are required to complete this method*/

    /* Function to get the middle of the linked list*/
    /*K will always be in range */

    class Solution
{
public:
    Node *deleteK(Node *head, int K)
    {
        if (K == 1)
            return NULL;
        int k = 1;
        Node *t = head;
        while (t != NULL && t->next != NULL && k++)
            if (k == K)
            {
                t->next = t->next->next;
                t = t->next;
                k = 1;
            }
            else
                t = t->next;
        return head;
    }
};