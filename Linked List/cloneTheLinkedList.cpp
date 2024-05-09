// Problem Link : https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

class Solution
{
public:
    Node *copyList(Node *head)
    {
        // Write your code here
        // adding nodes in between
        Node *tmp = head;
        while (tmp)
        {
            Node *newNode = new Node(tmp->data);
            newNode->next = tmp->next;
            tmp->next = newNode;
            tmp = tmp->next->next;
        }
        // adding random pointers to the newly added nodes
        tmp = head;
        while (tmp)
        {
            if (tmp->arb)
                tmp->next->arb = tmp->arb->next;
            else
                tmp->next->arb = NULL;
            tmp = tmp->next->next;
        }
        // changing back the next pointers in both the linkedlists
        Node *dummyHead = new Node(-1);
        Node *tmp2 = dummyHead;
        tmp = head;
        while (tmp)
        {
            tmp2->next = tmp->next;
            tmp2 = tmp2->next;
            tmp->next = tmp->next->next;
            tmp = tmp->next;
        }
        return dummyHead->next;
    }
};