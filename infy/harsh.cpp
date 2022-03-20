#include <bits/stdc++.h>
using namespace std;


int dist(int mid,vector<int> A,int N,int C)
{
    int cost=0;
    for(int i=0;i<N;i++)
    {
        cost+=abs(A[i]-A[mid])*C;
    }
    return cost;
}

int minRange(int N,int D,int C,vector<int> A)
{
    for(int i=0;i<N;i++)
    {
        A[i]=A[i]%D;
    }
    int minimum=INT32_MAX;
    sort(A.begin(),A.end());
    int i=0,j=N-1;
    while(i<j)
    {
        int mid = (i + j)/2;
        int temp=dist(mid,A,N,C);
        if(temp<minimum)
        {
            i = mid + 1;
            minimum=temp;
        }
        else
        {
            j = mid;
        }
    }
    return minimum;
}

int main()
{
    vector<int>A{8,84,89};
    cout<<minRange(A.size(),5,1,A);
    return 0;
}