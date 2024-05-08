// Problem Link : https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        Node *end = head;
        Node *start = head;
        while (end->next)
        {
            end = end->next;
        }
        vector<pair<int, int>> ans;
        while (start && end && start->data < end->data)
        {
            if (start->data + end->data == target)
            {
                ans.push_back({start->data, end->data});
                start = start->next;
                end = end->prev;
            }
            else if (start->data + end->data < target)
            {
                start = start->next;
            }
            else
                end = end->prev;
        }
        return ans;
    }
};