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
    Node *solveRecursive(Node *arr[], int K)
    {
        Node *dummyHead = new Node(-1);
        Node *tmp = dummyHead;
        priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> q;
        for (int i = 0; i < K; i++)
        {
            q.push({arr[i]->data, arr[i]});
        }
        while (!q.empty())
        {
            pair<int, Node *> p = q.top();
            q.pop();
            tmp->next = p.second;
            tmp = tmp->next;
            if (p.second->next)
            {
                q.push({(p.second->next)->data, p.second->next});
            }
        }
        tmp = dummyHead;
        dummyHead = dummyHead->next;
        free(tmp);
        return dummyHead;
    }

    Node *mergeKLists(Node *arr[], int K)
    {
        // Your code here
        // There are two ways to solve this question, first one takes the help of the recursion and second one uses min-heap

        /* RECURSION ONE */

        // if (K - 1 == 0)
        //     return arr[K - 1];
        // Node *secondRoot = mergeKLists(arr, K - 1);
        // arr[K - 1] = mergeLinkedLists(arr[K - 1], secondRoot);
        // return arr[K - 1];

        /* MIN HEAP ONE */
        Node *head = solveRecursive(arr, K);
        return head;
    }
};