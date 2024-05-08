// Problem Link : https://www.naukri.com/code360/problems/introduction-to-doubly-linked-list_8160413?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

/*
 * Definition for doubly-linked list.
 * class Node
 * {
 * public:
 *    int data;
 *    Node *next, *prev;
 *    Node() : data(0), next(nullptr), prev(nullptr) {}
 *    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
 *    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
 * };
 */

Node *constructDLL(vector<int> &arr)
{
    // Write your code here
    Node *Head = new Node(-1);
    Node *tmp = Head;
    for (auto x : arr)
    {
        Node *newNode = new Node(x);
        newNode->prev = tmp;
        tmp->next = newNode;
        tmp = newNode;
    }
    Head = Head->next;
    return Head;
}
