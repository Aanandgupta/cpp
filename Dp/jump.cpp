//order(n*k)

#include <bits/stdc++.h>
using namespace std;

int nways(int n,int k,vector<int>  &store)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    int temp=k;
    while(temp!=0)
    {
        if(n>=temp and store[n-temp]!=0)
        {
            store[n]+=store[n-temp];
        }
        else{
            store[n]+=nways(n-temp,k,store);
        }
        temp--;
    }

    return store[n];
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> store(n+1,0);
    cout << nways(n,k,store);

    return 0;
}