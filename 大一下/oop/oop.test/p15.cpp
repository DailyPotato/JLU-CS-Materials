# include <iostream>

using namespace std;
int* arr[10]={};
int index=0;

class A
{
    public:
    A(int n)
    {
        cout<<"create A with n: "<<n<<endl;
        int *p = new int(n);
        arr[index++] = p;
    }
    void* operator new(size_t size)
    {
        cout << "new A" << endl;
        return new A(10);
    }
    void* operator new(size_t size, int n)
    {
        cout << "new A with n" << endl;
        return ::new A(n);
    }
    private:
    int num;
    int *p;
};


int main()
{
    A *a = new A(5);
    // A *b = new (1) A(2);
    // cout<<"arr[0]: "<<*arr[0]<<endl;
    // cout<<"arr[1]: "<<*arr[1]<<endl;

    return 0;
}