#include <bits/stdc++.h>
using namespace std;

void climbing(int open,int close,string s)
{
    if(close==0)
    {
        cout << s << endl;
        return ;
    }
    if(open>0)
    {
    climbing(open-1,close,s+"(");
    }
    if(close>open)
    {
    climbing(open,close-1,s+")");
    }
}

int main()
{
    int n=3;
    int open=n,close=n;
    string s="";
    climbing(open,close,s);
    return 0;
}