#include <iostream>
#include <utility>
#define PI 3.141592653589793
using namespace std;
#define MAXLEN 30
class CTF
{
public:
    CTF(long double n):len(0)
    {
        long double temp=n;
        while(static_cast<int>(temp)&&len<MAXLEN)
        {
            // cout<<static_cast<int>(temp)<<endl;
            arr[len]=static_cast<int>(temp);
            temp-=arr[len];
            temp=1/temp;
            len++;
        }
    }
    int getA_i(int i)
    {
        return arr[i-1];
    }
    pair<int,int> getF(int q)
    {
        int fenzi=arr[q-1];
        int fenmu=1;
        for(int i=q-1;i>0;i--)
        {
            int temp=fenmu;
            fenmu=fenzi;
            fenzi=temp+arr[i-1]*fenmu;
        }
        return make_pair(fenzi,fenmu);
    }
    void print(int q)
    {
        for(int i=0;i<q-1;i++)
        {
            cout<<arr[i]<<"+";
        }
        cout<<arr[q-1];
    }
private:
int len;
int arr[MAXLEN];
};



int main()
{
    CTF a(PI);
    for(int i=1;i<=10;i++)
    {
        cout<<"前"<<i<<"项为"<<a.getA_i(i)<<endl;
        cout<<"前"<<i<<"项的分数为"<<a.getF(i).first<<"/"<<a.getF(i).second<<endl;
        cout<<"前"<<i<<"项对应的分支值为"<<static_cast<long double>(a.getF(i).first)/a.getF(i).second<<endl;
        cout<<"前"<<i<<"项对应分数与PI的差值为"<<static_cast<long double>(a.getF(i).first)/a.getF(i).second-PI<<endl<<endl;
    }
    return 0;
}