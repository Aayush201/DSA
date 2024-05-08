// Problem Link : https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

// Function to find intersection point in Y shaped Linked Lists.int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    int count1 = 0, count2 = 0;
    Node *temp1 = head1, *temp2 = head2;
    while (temp1)
    {
        count1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        count2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    if (count1 > count2)
    {
        int k = count1 - count2;
        while (k--)
        {
            temp1 = temp1->next;
        }
    }
    else if (count1 < count2)
    {
        int k = count2 - count1;
        while (k--)
        {
            temp2 = temp2->next;
        }
    }
    while (temp1 && temp2 && temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1)
        return temp1->data;
    return -1;
}