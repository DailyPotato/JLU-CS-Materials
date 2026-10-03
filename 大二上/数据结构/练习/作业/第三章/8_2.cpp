struct Node
{
    int data;
    Node *next;
};

int SelectItem(Node *&top, int n)
{
    Node *p = top;
    Node *prev = nullptr;
    int pos = 0;
    while (p != nullptr && p->data != n)
    {
        prev = p;
        p = p->next;
        pos++;
    }
    if (p == nullptr)
        return -1;
    if (p == top)
        return pos;
    prev->next = p->next;
    p->next = top;
    top = p;
    return pos;
}