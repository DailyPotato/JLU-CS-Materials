#include<iostream>
using namespace std;

void f(int n,int m)
{
    int **p=new int*[n];
    for(int i=0;i<n;i++)
    {
        p[i]=new int[m];
    }
    int k=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            p[i][j]=k++;
        }
    }
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<m;j++)
        {
            sum+=p[i][j];
        }
        cout<<"第"<<i+1<<"行的和为"<<sum<<endl;
    }
    for(int i=0;i<m;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=p[j][i];
        }
        cout<<"第"<<i+1<<"列的和为"<<sum<<endl;
    }
    for(int i=0;i<n;i++)
    {
        delete[] p[i];
    }
    delete[] p;
    return;
}

int main()
{
    int n,m;
    cin>>n>>m;
    f(n,m);
    return 0;
}