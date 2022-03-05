#include <bits/stdc++.h>
using namespace std;


void ways(int n,int x,int h,vector<int> arr,map <int,int,greater<int>> &ans,int i,vector<int> &dp)
{
   if(i==n)
    {
        return;
    }
    dp[i]++;
    if(x>0)
    {
        ways(n,x-1,h,arr,ans,i+1,dp);
    }
       
    if(h-arr[i]>0)
    {
        ways(n,x,h-arr[i],arr,ans,i+1,dp);
    }
    return ;
}

int main(){

    int h,n,x;
    cin>>h>>n>>x;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    vector<int> dp(n,0);
    map <int,int,greater<int>> ans;
    ways(n,x,h,arr,ans,0,dp);
    int prev=0,cur=0;
    for(int i=0;i<n;i++)
    {
        cout<<dp[i];
        cur=dp[i];
        if(cur==0)
        {
            cout<<endl<<prev;
        }
        prev=cur;
    }
    return 0;
}