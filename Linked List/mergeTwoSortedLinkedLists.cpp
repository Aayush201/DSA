// Problem Link : https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to merge two sorted linked list.
Node *sortedMerge(Node *head1, Node *head2)
{
    // code here
    Node *newHead = new Node(-1);
    Node *tmp1 = head1, *tmp2 = head2, *tmp3 = newHead;
    while (tmp1 && tmp2)
    {
        if (tmp1->data < tmp2->data)
        {
            tmp3->next = tmp1;
            tmp1 = tmp1->next;
            tmp3 = tmp3->next;
        }
        else
        {
            tmp3->next = tmp2;
            tmp2 = tmp2->next;
            tmp3 = tmp3->next;
        }
    }
    while (tmp1)
    {
        tmp3->next = tmp1;
        tmp1 = tmp1->next;
        tmp3 = tmp3->next;
    }
    while (tmp2)
    {
        tmp3->next = tmp2;
        tmp2 = tmp2->next;
        tmp3 = tmp3->next;
    }
    tmp3->next = NULL;
    tmp1 = newHead;
    newHead = newHead->next;
    free(tmp1);
    return newHead;
}
