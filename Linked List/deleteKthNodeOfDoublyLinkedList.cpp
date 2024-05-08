// Problem Link : https://www.naukri.com/code360/problems/delete-k-th-node-from-doubly-linked-list_9723679?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int val;
 *		Node *next;
 * 		Node *prev;
 *		Node() : val(0), next(nullptr), prev(nullptr){};
 *		Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *		Node(int x, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
 * };
 */

Node *deleteNode(Node *head, int k)
{
    Node *tmp = head;
    if (k == 1)
    {
        head = head->next;
        if (head)
            head->prev = NULL;
        return head;
    }
    k--;
    while (k--)
    {
        tmp = tmp->next;
    }
    // cout << tmp->val << endl;
    if (tmp->prev == NULL)
    {
        tmp = tmp->next;
        tmp->prev = NULL;
        head = tmp;
    }
    else if (tmp->next == NULL)
    {
        tmp->prev->next = NULL;
    }
    else
    {
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
    }
    return head;
}