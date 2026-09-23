#include<iostream>
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
void DeleteData(Node* head,int mink,int maxk)
{
    if(head==nullptr||head->next==nullptr)return;

    Node* p=head;
    while(p->next!=nullptr&&p->next->data<=mink)
    {
        p=p->next;
    }
    while(p->next!=nullptr&&p->next->data<maxk)
    {
        Node* temp=p->next;
        p->setNext(temp->next);
        delete temp;
    }
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
    DeleteData(head, 1, 5);
    for(Node *p = head->next; p != nullptr; p = p->next)
    {
        cout << p->data << " ";
    }
}