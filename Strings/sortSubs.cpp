#include <bits/stdc++.h>
using namespace std;


void subs(string s,string output)
{
    if(s=="")
    {
        cout << output << "   ";
        return ;
    }
    subs(s.substr(1),output+s[0]);
    subs(s.substr(1),output);
}

int main()
{
    string s="abc",output="";
    subs(s,output);

    return 0;
}