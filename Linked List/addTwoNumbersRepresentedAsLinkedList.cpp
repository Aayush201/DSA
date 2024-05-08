// Problem link : https://www.naukri.com/code360/problems/add-two-numbers_1170520?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *dummyHead = new Node(-1);
    Node *tmp1 = num1, *tmp2 = num2, *tmp3 = dummyHead;
    int carry = 0;
    while (tmp1 || tmp2)
    {
        int val = 0;
        if (tmp1)
        {
            val += tmp1->data;
            tmp1 = tmp1->next;
        }
        if (tmp2)
        {
            val += tmp2->data;
            tmp2 = tmp2->next;
        }
        val += carry;
        Node *newNode = new Node(val % 10);
        carry = val / 10;
        tmp3->next = newNode;
        tmp3 = tmp3->next;
    }
    if (carry)
    {
        Node *newNode = new Node(carry);
        tmp3->next = newNode;
    }
    dummyHead = dummyHead->next;
    return dummyHead;
}
