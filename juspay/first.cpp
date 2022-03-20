#include <bits/stdc++.h>
using namespace std;
 

void main()
{
    int v,t;
    cin>>v;
    map<int,vector<int>> m;
    int ljp=0;
    while(ljp<v)
    {
        cin>>t;
        ljp++;
    }
    cin>>t;
    int t1,t2;
    for(int x=0;x<t;x++)
    {
        cin>>t1>>t2;
        m[t2].push_back(t1);
        m[t1].push_back(t2);
    }
    
    int source, dest;
    cin>>source>>dest;
    queue<pair<int,int>> queue;
    queue.push({source,0});
    //int mini = INT_MAX;
    unordered_set<int> vsiited;
    int f=0;
    //cout<<"h";
    while(!queue.empty()){
        pair<int,int> hl=queue.front();
        int x = hl.first;
        int y = hl.second;
        queue.pop();
        for(auto i : m[x]){
            if(vsiited.find(i)==vsiited.end()){
                vsiited.insert(i);
                queue.push({i,y+1});
            }
        }
    }
        if(vsiited.find(dest)!=vsiited.end())
        cout<<"1"<<endl;
        else{
            cout<<"0"<<endl;
        }
}