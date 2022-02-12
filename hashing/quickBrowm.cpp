#include <bits/stdc++.h>
using namespace std;


int findMinBars(string s,unordered_set<string> all,int i)
{
    if(i==s.size())
    {
        return 0;
    }
    string x="";
    int minBars=INT_MAX;
    for(int j=i;j<s.size();j++)
    {
        x+=s[j];
        if(all.find(x)!=all.end())
        {
            int temp=findMinBars(s,all,j+1);
            if(temp!=-1)
            {
                minBars=min(minBars,temp+1);
            }
        }
    }
    if(minBars==INT_MAX)
    {
        return -1;
    }
    return minBars;

}
int main()
{
    string s,temp;
    int n;
    unordered_set <string> all;
    cin>>s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        all.insert(temp);
    }

    cout<<findMinBars(s,all,0);
    return 0;
}