#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
    void setNext(Node *nextNode)
    {
        next = nextNode;
    }
};

void reverseList(Node* head)
{
    if (head == nullptr)
        return;

    Node* prev = nullptr;
    Node* current = head->next;

    while (current != nullptr)
    {
        Node* nextNode = current->next;

        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head->next = prev;
}

int main()
{
    Node *head = new Node(0);
    Node *p = head;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        Node *newNode = new Node(x);
        p->setNext(newNode);
        p = newNode;
    }
    reverseList(head);
    for(Node *p = head->next; p != nullptr; p = p->next)
    {
        cout << p->data << " ";
    }
}
