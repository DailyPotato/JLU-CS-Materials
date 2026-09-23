#include<iostream>
#include<vector>
using namespace std;

void Reverse(vector<int>&arr,int n)
{
    int start = 0;
    int end = n-1;
    int temp=arr[end];
    while(start < end)
    {
        arr[end]=arr[start];
        arr[start]=temp;
        start++;
        end--;
        temp=arr[end];
    }
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
    Reverse(arr,5);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}