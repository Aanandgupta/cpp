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
        vector <int> distance(vertex,INT_MAX);
        set <pair<int,int>> weights;
        weights.insert({0,start});
    distance[start]=0;

        while(!weights.empty())
        {
            auto l1= weights.begin();
            int currentWeight=l1->first;
            int source=l1->second;
            weights.erase(l1);
            for(auto it:l[source])
            {
                int nbr=it.second;
                int nbrweight=it.first;
                if(nbrweight+currentWeight<distance[nbr])
                {
                    if(weights.find({distance[nbr],nbr})!=weights.end())
                    {
                        weights.erase({distance[nbr],nbr});
                    }
                    distance[nbr]=nbrweight+currentWeight;

                    weights.insert({nbrweight+currentWeight,nbr});
                }
            }
        }
        for(int i=0;i<vertex;i++)
        {
            cout<<start<<"to"<<i<<"distance is--"<<distance[i]<<endl;
        }
        return distance[end];
    }

};

int main()
{
    graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);

    cout <<g.dijkastra(0,4);

    return 0;
}