#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int>> arr{{1,2},{2,0},{2,2},{2,3},{4,2}};
    unordered_map <int,int> x;
    unordered_map <int,int> y;

    int ans=0;
    for(pair<int,int> i:arr)
    {
        if(x.find(i.first)==x.end())
            x[i.first]=1;
        else
            x[i.first]++;
        if(y.find(i.second)==y.end())
            y[i.second]=1;
        else
            y[i.second]++;
            // x[i.first]++;
    }
    for(pair<int,int> i:arr)
    {
        ans+=(x[i.first]-1)*(y[i.second]-1);
    }
    cout << ans;

    return 0;

}