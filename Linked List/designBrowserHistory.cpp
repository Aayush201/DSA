// Problem Link : https://www.geeksforgeeks.org/problems/design-browser-history/1

// User function Template for C++
class Node
{
public:
    string data;
    Node *prev;
    Node *next;
    Node(string data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class BrowserHistory
{
public:
    // constructor to initialize object with homepage
    Node *tail;
    BrowserHistory(string homepage)
    {
        Node *newNode = new Node(homepage);
        tail = newNode;
    }

    // visit current url
    void visit(string url)
    {
        Node *newNode = new Node(url);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // 'steps' move backward in history and return current page
    string back(int steps)
    {
        while (tail->prev && steps--)
        {
            tail = tail->prev;
        }
        return tail->data;
    }

    // 'steps' move forward and return current page
    string forward(int steps)
    {
        while (tail->next && steps--)
        {
            tail = tail->next;
        }
        return tail->data;
    }
};