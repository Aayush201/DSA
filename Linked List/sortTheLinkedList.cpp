// Problem Link : https://www.geeksforgeeks.org/problems/sort-a-linked-list/1

/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
    // Function to sort the given linked list using Merge Sort.
    Node *middleFinder(Node *head)
    {
        Node *slow = head;
        // following line handles both even and odd length testcases
        Node *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *mergeLinkedLists(Node *root1, Node *root2)
    {
        Node *dummyHead = new Node(-1);
        Node *tmp = dummyHead;
        while (root1 && root2)
        {
            if (root1->data < root2->data)
            {
                tmp->next = root1;
                root1 = root1->next;
            }
            else
            {
                tmp->next = root2;
                root2 = root2->next;
            }
            tmp = tmp->next;
        }
        if (root1)
            tmp->next = root1;
        else
            tmp->next = root2;
        tmp = dummyHead;
        dummyHead = dummyHead->next;
        free(tmp);
        return dummyHead;
    }
    Node *mergeSort(Node *head)
    {
        // your code here
        if (head == NULL || head->next == NULL)
            return head;
        Node *middle = middleFinder(head);
        Node *start = head, *nextStart = middle->next;
        middle->next = NULL;
        Node *left = mergeSort(start);
        Node *right = mergeSort(nextStart);

        return mergeLinkedLists(left, right);
    }
};