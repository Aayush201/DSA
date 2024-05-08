// Problem link : https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        // code here
        Node *oddHead = new Node(-1);
        Node *evenHead = new Node(-1);
        Node *odd = oddHead, *even = evenHead;
        Node *tmp = head;
        while (tmp)
        {
            if (tmp->data % 2 == 0)
            {
                even->next = tmp;
                even = even->next;
            }
            else
            {
                odd->next = tmp;
                odd = odd->next;
            }
            tmp = tmp->next;
        }
        evenHead = evenHead->next;
        oddHead = oddHead->next;
        if (evenHead == NULL)
            return oddHead;
        odd->next = NULL;
        even->next = oddHead;
        return evenHead;
    }
};