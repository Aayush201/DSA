// Problem Link : https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

/*  Function which returns the  root of
    the flattened linked list. */
Node *mergeLinkedLists(Node *root1, Node *root2)
{
    Node *dummyHead = new Node(-1);
    Node *tmp = dummyHead;
    while (root1 && root2)
    {
        if (root1->data < root2->data)
        {
            tmp->bottom = root1;
            root1 = root1->bottom;
            tmp = tmp->bottom;
        }
        else
        {
            tmp->bottom = root2;
            root2 = root2->bottom;
            tmp = tmp->bottom;
        }
    }
    while (root1)
    {
        tmp->bottom = root1;
        root1 = root1->bottom;
        tmp = tmp->bottom;
    }
    while (root2)
    {
        tmp->bottom = root2;
        root2 = root2->bottom;
        tmp = tmp->bottom;
    }
    tmp = dummyHead;
    dummyHead = dummyHead->bottom;
    free(tmp);
    return dummyHead;
}
Node *flatten(Node *root)
{
    // Your code here
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    Node *secondRoot = flatten(root->next);
    root = mergeLinkedLists(secondRoot, root);
    return root;
}
