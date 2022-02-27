#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    string name;
    vector <string> nbrs;
    Node(string n)
    {
        name=n;
    }
};


class graph
{
    public:
    unordered_map <string,Node *> l;
    graph(vector <string> s)
    {
       
        for(string i:s)
        {
            l[i]=new Node(i);
        }
    }
    void addEdge(string a,string b,bool undir=true)
    {
        l[a]->nbrs.push_back(b);
        if(undir)
        {
            l[b]->nbrs.push_back(a);
        }
    } 

    void print()
    {
        for(auto it:l)
        {
            cout<<it.first<<" ";
            for(string i:l[it.first]->nbrs)
            {
                cout<<"---"<<i;
            }
        }
    }
};

int main()
{
    vector <string> cities{"delhi","knp","lko","pryag","gzb"};
    graph g(cities);
    g.addEdge("delhi","knp");
    g.addEdge("knp","gzb");
    g.addEdge("delhi","lko");
    g.addEdge("delhi","pryag");
    g.addEdge("gzb","pryag");
    g.print();
    return 0;
}