// Problem Link : https://www.geeksforgeeks.org/problems/intersection-of-two-linked-list/1

/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        // code here
        // return the head of intersection list
        Node *dummyHead = new Node(-1);
        Node *tmp1 = head1;
        Node *tmp2 = head2;
        Node *tmp = dummyHead;
        unordered_map<int, int> mp;
        while (tmp2)
        {
            mp[tmp2->data]++;
            tmp2 = tmp2->next;
        }
        while (tmp1)
        {
            if (mp[tmp1->data])
            {
                Node *newNode = new Node(tmp1->data);
                tmp->next = newNode;
                tmp = tmp->next;
            }
            tmp1 = tmp1->next;
        }
        tmp = dummyHead;
        dummyHead = dummyHead->next;
        free(tmp);
        return dummyHead;
    }
};