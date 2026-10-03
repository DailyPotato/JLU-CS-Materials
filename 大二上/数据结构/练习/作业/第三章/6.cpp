#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    int freq;
    Node *next;
    Node *prior;
    Node(int val) : data(val), freq(0), next(nullptr), prior(nullptr) {}
};
void Locate(Node *head, int x)
{
    if (head == nullptr || head->next == nullptr)
        return;
    Node *front = head, *prev = head;
    Node *p = head->next;
    while (p != nullptr && p->data != x)
    {
        prev = p;
        if (p->next != nullptr && p->freq > p->next->freq)
        {
            front = p;
        }
        p = p->next;
    }
    if (p == nullptr)
        return;
    p->freq++;
    if(front==prev)
        return;
    Node *temp = front->next;
    front->next = p;
    prev->next = p->next;
    p->next = temp;
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
        p->next = newNode;
        newNode->prior = p;
        p = newNode;
    }
    for (Node *p = head->next; p != nullptr; p = p->next)
    {
        cout << p->data << " ";
    }
    int x=-1;
    while (cin >> x && x != -1)
    {
        Locate(head, x);
        for (Node *p = head->next; p != nullptr; p = p->next)
        {
            cout << p->data << " ";
        }
        cout << endl;
    }
}
