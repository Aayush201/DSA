Node *deleteNode(Node *head, int x)
{
    Node *newNode = head;
    if (x == 1)
    {
        newNode = newNode->next;
        return newNode;
    }
    --x;
    if (!head)
        return NULL;
    while (--x)
    {
        newNode = newNode->next;
    }
    newNode->next = newNode->next->next;
    return head;
}