#include <iostream>

void sort(int &a,int &b)
{
    a>b?void():std::swap(a,b);
}
void sort(int &a,int &b,int &c)
{
    sort(a,b);
    sort(a,c);
    sort(b,c);
}

int main()
{
    int a,b,c;
    std::cin>>a>>b>>c;
    sort(a,b,c);
    int e,f;
    std::cin>>e>>f;
    sort(e,f);
    std::cout<<a<<" "<<b<<" "<<c<<std::endl<<e<<" "<<f<<std::endl;
    return 0;

}