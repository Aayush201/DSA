// Problem Link : https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/*

  Node is defined as
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
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);
        Node *zero = zeroHead, *one = oneHead, *two = twoHead;
        Node *tmp = head;
        while (tmp)
        {
            if (tmp->data == 0)
            {
                zero->next = tmp;
                zero = zero->next;
            }
            else if (tmp->data == 1)
            {
                one->next = tmp;
                one = one->next;
            }
            else
            {
                two->next = tmp;
                two = two->next;
            }
            tmp = tmp->next;
        }
        one->next = NULL;
        two->next = NULL;
        oneHead = oneHead->next;
        twoHead = twoHead->next;
        zero->next = oneHead ? oneHead : twoHead;
        one->next = twoHead;
        zeroHead = zeroHead->next;
        return zeroHead;
    }
};
