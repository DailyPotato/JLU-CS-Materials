#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

class CTNFRACTION
{
public:
    CTNFRACTION(double n)
    {
        double temp=n;
        while(temp>1e-6)
        {
            arr[len++]=static_cast<int>(temp);
            temp=1/(temp-arr[len-1]);
        }
    }
    int geta_i(int i)
    {
        if(i>=len) return -1;
        return arr[i];
    }
    pair<int, int> calFraction(int q)
    {
        int numerator=1;
        int denominator=1;
        for(int i=q-1;i>=0;i--)
        {
            if(i==len-1)
            {
                numerator=arr[i];
                denominator=1;
            }
            else
            {
                int temp=denominator;
                denominator=arr[i]*denominator+numerator;
                numerator=temp;
            }
        }
        return make_pair(numerator, denominator);
    }

private:
    int MAXLEN=30;
    int arr[30];
    int len=0;
};

int main()
{
    double n;
    cin>>n;
    CTNFRACTION ctn(n);
    return 0;
}