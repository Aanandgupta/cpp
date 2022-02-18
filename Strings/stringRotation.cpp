#include <bits/stdc++.h>

using namespace std;


bool check(string s1,string s2)
{
    s1=s1+s1;
    for(int i=0;i<=s1.size()-s2.size();i++)
    {
        if(s1.substr(i,s2.size())==s2)
        return true;
    }
    return false;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<check(s1,s2);
    return 0;
}