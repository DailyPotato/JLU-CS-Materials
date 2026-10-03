struct Stack
{
    int data[100];
    int top;
};

int SelectItem(Stack &S, int n)
{
    int i;
    for (i = S.top; i >= 0; i--)
    {
        if (S.data[i] == n)
            break;
    }
    if (i < 0)
        return -1;
    int pos = i;
    for (int j = i; j < S.top; j++)
    {
        S.data[j] = S.data[j + 1];
    }
    S.data[S.top] = n;
    return pos;
}