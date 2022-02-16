#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    string name;
    vector <string> nbrs;
    Node(string Name)
    {
        name=Name;
    }
};

class Graph
{
    public:
    unordered_map <string,Node *> m;
    Graph(vector<string> cities)
    {
        for(string city:cities)
        {
            m[city]=new Node(city);
        }
    }

    void addEdge(string city1,string city2,bool undir=true)
    {
        m[city1]->nbrs.push_back(city2);
        if(undir)
        {
            m[city2]->nbrs.push_back(city1);
        }
    }

    void display()
    {
        for(auto cur:m)
        {
            cout<<cur.first<<" ";
            for(string i:cur.second->nbrs)
            {
                cout<<i<<"--";
            }
            cout<<endl;
        }
    }
};


int main()
{
    vector <string> cities{"delhi","knp","lko","pryag","gzb"};
    Graph g(cities);
    g.addEdge("delhi","knp");
    g.addEdge("knp","gzb");
    g.addEdge("delhi","lko");
    g.addEdge("delhi","pryag");
    g.addEdge("gzb","pryag");

    g.display();
    return 0;
}