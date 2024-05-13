// Problem Link : https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    void reverse(Node *&head)
    {
        Node *curr = head, *prev = NULL;
        while (curr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        reverse(head);
        Node *tmp = head;
        while (tmp)
        {
            Node *nxt = tmp->next;
            while (nxt && nxt->data < tmp->data)
            {
                nxt = nxt->next;
            }
            tmp->next = nxt;
            tmp = tmp->next;
        }
        reverse(head);
        return head;
    }
};
