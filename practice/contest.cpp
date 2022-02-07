#include<bits/stdc++.h>
using namespace std;
int find(vector <int> A,vector<int> B)
{
 int sum1=0,sum2=0;
 vector <int> pre(A.size(),0);
 vector <int> post(A.size(),0);
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0)
        {
            sum1+=B[i];
        }
        else{
            sum2+=B[i];
        }
    }
    
    int ans1=0,ans2=0,j=0;
    while(j<A.size())
    {
        if(A[j]==0)
        {
            ans1+=B[j];
        }
        else{
            ans2+=B[j];
        }
        if(j!=0)
        {
            pre[j]=max(pre[j-1],ans2-ans1);
        }
        j++;
    }
    ans1=0;
    ans2=0;j=A.size();
    while(j>=0)
    {
        if(A[j]==0)
        {
            ans1+=B[j];
        }
        else{
            ans2+=B[j];
        }
        if(j!=A.size())
        {
            post[j]=max(post[j+1],ans2-ans1);
        }
        j--;
    }
    
    return (sum1+max(pre[A.size()],post[0]));
}

int main()
{
    vector<int> A={0,1,1,0,0},B={39,12,6,46,33};
    cout<<find(A,B);
}