#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

struct Triple
{
    int row;
    int col;
    int data;
};

vector<Triple> func(vector<Triple>& matrix,int n)
{
    vector<int>count(n,0);
    vector<int>pos(n,0);
    for(int i = 0; i < matrix.size(); i++)
    {
        count[matrix[i].col]++;
    }
    for(int i = 1; i < n; i++)
    {
        pos[i] = pos[i-1] + count[i-1];
    }
    vector<Triple> temp(matrix.size());
    for(int i = 0; i < matrix.size(); i++)
    {
        int col = matrix[i].col;
        int p = pos[col];
        temp[p].row = matrix[i].col;
        temp[p].col = matrix[i].row;
        temp[p].data = matrix[i].data;
        pos[col]++;
    }
    return temp;
}


int main()
{
    vector<Triple> matrix={
        {0,0,1},
        {0,2,2},
        {1,1,3},
        {2,0,4},
        {2,2,5}
    };
    vector<Triple> result = func(matrix,3);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i].row << " " << result[i].col << " " << result[i].data << endl;
    }
    return 0;
}