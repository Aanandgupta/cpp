#include <bits/stdc++.h>
using namespace std;

class graph
{
    int vertex;
    list <pair<int,int>> *l;
    public:
    graph(int v)
    {
        vertex=v;
        l=new list<pair<int,int>>[v];
    }


    void addEdge(int source,int destination,int weight,bool undir=true)
    {
        l[source].push_back({weight,destination});
        if(undir)
        {
        l[destination].push_back({weight,source});
        }
    }


    int dijkastra(int start,int end)
    {
        vector <int> visited(vertex,INT_MAX);
        set <pair<int,int>> distance;
        distance.insert({0,start});

        while(!distance.empty())
        {
            auto it=distance.begin();
            int weight=it->first;
            int source=it->second;
            for(auto i:l[source])
            {
                int curDistance=i.first;

                if(visited[i.second]==INT_MAX)
                {
                    visited[i.second]=i.first;

                }
            }
        }


    }

};

int main()
{
    return 0;
}