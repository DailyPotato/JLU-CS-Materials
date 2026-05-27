#include <iostream>
using namespace std;

class TOdArray
{
public:
    TOdArray(int rol,int col):row(row),col(col)
    {
        data=new int*[row];
        for(int i=0;i<row;i++)
        {
            data[i]=new int[col];
        }
    }
    int * operator[](int index)
    {
        return data[index];
    }
    int * operator[](int index) const
    {
        return data[index];
    }

private:
    int **data;
    int row;
    int col;
};

int main()
{
    TOdArray obj(3,4);
    int k=1;
    obj[1][2]=5;
    cout<<obj[1][2]<<endl;
    return 0;
}