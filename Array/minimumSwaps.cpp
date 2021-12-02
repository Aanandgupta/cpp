#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    vector <int> ary={10,11,5,4,3,2,1};
    int total=0,n=ary.size();
    pair <int,int> storedAry[ary.size()];

    for(int i=0;i<ary.size();i++)
    {
        storedAry[i].first=ary[i];
        storedAry[i].second=i;
    }
    sort(storedAry,storedAry+n);
    vector <bool> visited(ary.size(),0);

     for(int i=0;i<ary.size();i++)
    {
        if(i!=storedAry[i].second && !visited[i] )
        {
            visited[i]=true;
            int node=storedAry[i].second;
            int cycle=1;
            while(!visited[node])
            {
                cycle+=1;
                visited[node]=1;
                node=storedAry[node].second;
            }
            total+=cycle-1;

        }
    }

    cout << total;

    return 0;
}