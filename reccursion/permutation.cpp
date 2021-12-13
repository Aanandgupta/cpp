#include <bits/stdc++.h>
using namespace std;


void permutate(string s,int i,int len)
{
    int j=i;
    if(i==len)
    {
        cout << s;
        return ;
    }
    for(int j=i;j<len;j++)
    {
        swap(s[i],s[j]);
        permutate(s,i+1,len);
        swap(s[i],s[j]);
    }
}



int main()
{
    string s("abc");
    permutate(s,0,s.size());

    return 0;
}