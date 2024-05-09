// Problem Link : https://www.geeksforgeeks.org/problems/move-all-zeros-to-the-front-of-the-linked-list/1

/* Linked List Node structure
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
// Move Zeros to the front of the list
void moveZeroes(struct Node **head)
{
    // Your code here
    Node *zeroHead = new Node(-1);
    Node *nonZeroHead = new Node(-1);
    Node *zero = zeroHead, *nonZero = nonZeroHead, *tmp = *head;
    while (tmp)
    {
        if (tmp->data == 0)
        {
            zero->next = tmp;
            zero = zero->next;
        }
        else
        {
            nonZero->next = tmp;
            nonZero = nonZero->next;
        }
        tmp = tmp->next;
    }
    zero->next = NULL;
    nonZero->next = NULL;
    tmp = zeroHead;
    zeroHead = zeroHead->next;
    free(tmp);
    tmp = nonZeroHead;
    nonZeroHead = nonZeroHead->next;
    free(tmp);
    zero->next = nonZeroHead;
    if (zeroHead)
        *head = zeroHead;
    else
        *head = nonZeroHead;
}