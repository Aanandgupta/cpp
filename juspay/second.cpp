#include <bits/stdc++.h>
#define PI 3.14;
#define ll long long;
using namespace std;
vector<pair<long long int,long long int>> a[100000];
vector<int> jachuke(100000,0);
long long int mimi=999999999999999,res=0,dekho=mimi;
void sample()
{
    return;
}
void dfs(long long int u,long long int v)
{
if(u==v)
{
if(mimi>res)
{
mimi=res;
}
}
jachuke[u]=1;
for(auto j: a[u])
{
if(jachuke[j.first]==0)
{
res+=j.second;
jachuke[j.first]==1;
dfs(j.first,v);
jachuke[j.first]==0;
res-=j.second;
}
}
jachuke[u]=0;
}
int main()
{
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
long long int n,e,x,y,i,w;
cin>>n;
for(i=0;i<n;i++)
{
cin>>x;
}
cin>>e;
for(i=0;i<e;i++)
{
cin>>x>>y>>w;
a[x].push_back({y,w});
}
cin>>x>>y;
dfs(x,y);
sample();
if(mimi==dekho)
cout<<"-1";
else
cout<<mimi;
return 0;
}