#include <bits/stdc++.h>
using namespace std;


void helper(int n,vector<int> A,int k,int &ans,int i,int j)
{
    if(k<0 || j==i)
        return;
    if(A[j]-A[i]<ans)
        ans=A[j]-A[i];
    helper(n,A,k-1,ans,i,j-1);
    helper(n,A,k-1,ans,i+1,j);
}

int minRange(int n,vector<int> A,int k)
{
    if(k==n-1)
        return 0;
    int ans=A[n-1]-A[0];
    helper(n,A,k,ans,0,n-1);
    return ans;
}

int main(){

    int n=5,k=4;
    // cin>>n;
    vector<int> arr{3,8,10,9,2};
    // for(int i=0;i<n;i++)
    // {
    //     int temp;
    //     cin>>temp;
    //     arr[i]=temp;
    // }
    // cin>>k;
    sort(arr.begin(),arr.end());
    cout<<minRange(n,arr,k);
    return 0;
}