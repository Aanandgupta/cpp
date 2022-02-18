#include <bits/stdc++.h>
using namespace std;

bool check(string s1, string s2)
{
    if(s2.size()<s1.size())
    {
        return false;
    }
    vector <int> arr1(26,0),arr2(26,0);
    for(char s:s1)
    {
        arr1[s-'a']+=1;
    }

    int count=0;
    for(int i=0;i<s1.size();i++)
    {
        if(arr2[s2[i]-'a']<arr1[s2[i]-'a'])
        {
            count++;
        }
        arr2[s2[i]-'a']+=1;
    }
    if(count==s1.size())
    {
        return true;
    }
    
    for(int i=s1.size();i<s2.size();i++)
    {
        if(arr2[s2[i-s1.size()]-'a']<=arr1[s2[i-s1.size()]-'a'])
        {
            count--;
        }
        if(arr2[s2[i]-'a']<arr1[s2[i]-'a'])
        {
            count++;
        }
        if(count==s1.size())
        {
            return true;
        }
        arr2[s2[i]-'a']+=1;
    
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