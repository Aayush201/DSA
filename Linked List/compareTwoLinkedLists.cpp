// Problem Link : https://www.geeksforgeeks.org/problems/compare-two-linked-lists/1

/* Linked list Node structure
struct Node
{
    char c;
    struct Node *next;

    Node(char x){
        c = x;
        next = NULL;
    }

};
*/

// Compare two strings represented as linked lists
int compare(Node *list1, Node *list2)
{
    // Code Here
    Node *tmp1 = list1, *tmp2 = list2;
    while (tmp1 && tmp2)
    {
        if (tmp1->c < tmp2->c)
            return -1;
        else if (tmp1->c > tmp2->c)
            return 1;
        else
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    if (!tmp1 && !tmp2)
        return 0;
    else if (tmp1)
        return 1;
    else
        return -1;
}