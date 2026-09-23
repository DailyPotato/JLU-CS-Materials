#include<iostream>
#include<vector>
using namespace std;

int minIndex(vector<int>&arr,int n)
{
    int min=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[min])
        {
            min=i;
        }
    }
    return min;
}

int main()
{
    vector<int>arr;
    for(int i=0;i<5;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int index=minIndex(arr,5);
    cout<<index;

}