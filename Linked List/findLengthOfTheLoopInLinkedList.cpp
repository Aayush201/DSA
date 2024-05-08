// Problem Link : https://www.geeksforgeeks.org/problems/find-length-of-loop/1

// Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *slow = head, *fast = head;
    int flag = 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            flag = 1;
            break;
        }
    }
    int ans = 0;
    if (flag && slow == fast)
    {
        Node *tmp = fast;
        while (tmp->next != fast)
        {
            ans++;
            tmp = tmp->next;
        }
        ans++;
    }
    return ans;
}