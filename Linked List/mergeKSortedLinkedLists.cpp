// Problem Link :  https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

/*Linked list Node structure

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
    // Function to merge K sorted linked list.
    Node *mergeLinkedLists(Node *root1, Node *root2)
    {
        Node *dummyHead = new Node(-1), *tmp = dummyHead;
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
        while (root1)
        {
            tmp->next = root1;
            root1 = root1->next;
            tmp = tmp->next;
        }
        while (root2)
        {
            tmp->next = root2;
            root2 = root2->next;
            tmp = tmp->next;
        }
        tmp = dummyHead;
        dummyHead = dummyHead->next;
        free(tmp);
        return dummyHead;
    }
    Node *mergeKLists(Node *arr[], int K)
    {
        // Your code here
        if (K - 1 == 0)
            return arr[K - 1];
        Node *secondRoot = mergeKLists(arr, K - 1);
        arr[K - 1] = mergeLinkedLists(arr[K - 1], secondRoot);
        return arr[K - 1];
    }
};