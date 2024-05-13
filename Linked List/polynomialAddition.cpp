// Problem Link : https://www.geeksforgeeks.org/problems/polynomial-addition/1

/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;

    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }

};
*/

class Solution
{
public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node *addPolynomial(Node *p1, Node *p2)
    {
        // Your code here
        Node *dummyHead = new Node(-1, -1);
        Node *tmp = dummyHead;
        Node *t1 = p1, *t2 = p2;
        while (t1 && t2)
        {
            if (t1->pow == t2->pow)
            {
                tmp->next = t1;
                t1->coeff += t2->coeff;
                t1 = t1->next;
                t2 = t2->next;
                tmp = tmp->next;
            }
            else if (t1->pow < t2->pow)
            {
                tmp->next = t2;
                t2 = t2->next;
                tmp = tmp->next;
            }
            else
            {
                tmp->next = t1;
                t1 = t1->next;
                tmp = tmp->next;
            }
        }
        while (t1)
        {
            tmp->next = t1;
            t1 = t1->next;
            tmp = tmp->next;
        }
        while (t2)
        {
            tmp->next = t2;
            t2 = t2->next;
            tmp = tmp->next;
        }
        tmp->next = NULL;
        tmp = dummyHead;
        dummyHead = dummyHead->next;
        free(tmp);
        return dummyHead;
    }
};
