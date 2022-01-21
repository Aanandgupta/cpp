#include <bits/stdc++.h>
using namespace std;

int climbing(int start,int end)
{
    if(start==end)
    {
        return 1;
    }
    if(start>end)
    {
        return 0;
    }
    return climbing(start+1,end)+climbing(start+2,end)+climbing(start+3,end);
}

int main()
{
    int n;
    cin >> n;
    cout << climbing(0,n);
    return 0;
}