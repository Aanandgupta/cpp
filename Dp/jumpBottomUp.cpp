//botto, u[p] O(n)


#include <bits/stdc++.h>
using namespace std;

int ways(int n,int k,vector<int> &store)
{
    store[0]=1;
    store[1]=1;
    for(int i=2;i<=k;i++)
    {
        store[i]=store[i-1]*2;
    }
    for(int i=k+1;i<=n;i++)
    {
        store[i]=2*store[i-1]-store[i-k-1];
    }
    return store[n];
}

int main()
{
    int n=6,k=4;
    // cin>>n>>k;
    vector<int> store(n+1,0);
    cout << ways(n,k,store);
    return 0;
}