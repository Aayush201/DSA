// Problem Link : https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

class Solution
{
public:
    // Function to check whether the list is palindrome.
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        while (curr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    bool isPalindrome(Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *newHead = slow->next;
        Node *tmp = reverse(newHead);
        // cout << tmp->data << endl;
        Node *tmp2 = head;
        // cout << tmp2->data << endl;
        while (tmp)
        {
            if (tmp->data != tmp2->data)
            {
                reverse(newHead);
                return false;
            }
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        reverse(newHead);
        return true;
    }
};