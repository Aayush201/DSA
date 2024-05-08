// Problem Link : https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

/*
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

class Solution
{
public:
    Node *reverseIterative(Node *head)
    {
        Node *prev = NULL, *curr = head;
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
    Node *solveIterative(Node *head)
    {

        head = reverseIterative(head);
        int carry = 1;
        Node *tmp = head;
        Node *pre;
        while (tmp)
        {
            tmp->data += carry;
            carry = tmp->data / 10;
            tmp->data %= 10;
            pre = tmp;
            tmp = tmp->next;
        }
        if (carry)
        {
            Node *newNode = new Node(carry);
            pre->next = newNode;
        }
        head = reverseIterative(head);
        return head;
    }
    int solveRecursive(Node *head)
    {
        if (head == NULL)
            return 1;
        int carry = solveRecursive(head->next);
        head->data += carry;
        carry = head->data / 10;
        head->data %= 10;
        return carry;
    }
    Node *addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        // There are two ways to do this question, first is using recursion and second one is iterative

        int carry = solveRecursive(head);
        if (carry)
        {
            Node *newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }
        // head = solveIterative(head);
        return head;
    }
};