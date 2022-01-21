#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1="codingminutes",s2="cines";
    int i=0,j=0;
    while(j<s1.size())
    {
        if(s1[j]==s2[i])
        {
            i++;
        }
        j++;
    }
    if(i==s2.size())
    {
        cout << "find";
    }
    else{
        cout << "not found";
    }
    return 0;
}