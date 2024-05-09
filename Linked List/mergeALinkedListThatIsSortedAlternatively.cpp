// Problem Link : https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1

/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    // your task is to complete this function
    Node *reverse(Node *head)
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
        return head;
    }
    void sort(Node **head)
    {
        // Code here
        Node *oddHead = new Node(-1);
        Node *evenHead = new Node(-1);
        Node *odd = oddHead, *even = evenHead;
        int flag = 0;
        Node *tmp = *head;
        while (tmp)
        {
            if (!flag)
            {
                odd->next = tmp;
                odd = odd->next;
            }
            else
            {
                even->next = tmp;
                even = even->next;
            }
            tmp = tmp->next;
            flag = !flag;
        }
        odd->next = NULL;
        even->next = NULL;
        tmp = oddHead;
        oddHead = oddHead->next;
        free(tmp);
        tmp = evenHead;
        evenHead = evenHead->next;
        free(tmp);
        evenHead = reverse(evenHead);
        odd->next = evenHead;
    }
};