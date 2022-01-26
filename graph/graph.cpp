#include <bits/stdc++.h>
using namespace std;

class graph{
    list<int> *l;
    int vertex;

    public:
    graph(int val)
    {
        vertex=val;
        l=new list<int>[val];
    }


    void addEdge(int s,int e,bool undir=true)
    {
        l[s].push_back(e);
        if(undir)
        {
            l[e].push_back(s);
        }
    }


    void print()
    {
        for(int i=0;i<vertex;i++)
        {
            cout << i<< "---";
            for(auto j:l[i])
            {
                cout <<j<<"--";
            }
            cout << endl;

        }
    }
    void bfsForDisConnected()
    {
        vector <bool>arr(vertex,false);
        queue <int> j;
        int cur;
       
        for(int i=0;i<vertex;i++)
        {
            if(arr[i]==false)
            {
                j.push(i);
                arr[i]=true;
                while(!j.empty())
                {
                    cur=j.front();
                    cout << cur;
                    for(auto x:l[cur])
                    {
                        if(arr[x]==false)
                        {
                            j.push(x);
                            arr[x]=true;
                        }
                    }
                    j.pop();
                }
            }

        }

    }
    void bfs(int source,int dest)
    {
        vector <bool>arr(vertex,false);
        vector <int>dist(vertex,0);
        vector <int>parent(vertex,-1);
        queue <int> j;
        int cur;
     
    
        j.push(source);
        arr[source]=true;
        parent[source]=source;
        while(!j.empty())
        {
            cur=j.front();
            j.pop();
            cout << cur;
            for(auto x:l[cur])
            {
                if(arr[x]==false)
                {
                    j.push(x);
                    dist[x]=dist[cur]+1;
                    parent[x]=cur;
                    arr[x]=true;
                }
            }
        }

        //shortest distance

        for(int i=0;i<vertex;i++)
        {
            cout<< "shortest distance of "<<i <<" from source "<< source<< " is "<<dist[i]<<endl;
        }

        //shortest path
        int temp=dest;
        while(temp!=source)
        { 
            cout<<"---"<<temp;
            temp=parent[temp];
        }
        cout << "--"<<source;

    }


    void dfs(int source,vector <bool> &visited)
    {
        int temp;
        visited[source]=true;
        cout<<source;
        for(int i:l[source])
        {
            if(visited[i]==false)
            {
                dfs(i,visited);
            }
        }
        
    }
    // void dfs(int source,vector <bool> &visited)
    // {
    //     int temp;
    //     visited[source]=true;
    //     cout<<source;
    //     for(int i:l[source])
    //     {
    //         if(visited[i]==false)
    //         {
    //             dfs(i,visited);
    //         }
    //     }
        
    // }



    bool detectCycle(int source,vector <bool> &visited,int parent)
    {
        
        visited[source]=true;
        for(int i:l[source])
        {
            if(visited[i]==false)
            {
                bool check= detectCycle(i,visited,source);
                if(check)
                {
                    return true;
                }
            }
            else{
                if(i!=parent)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
    bool detectDirectedCycle(int source,vector <bool> &visited,vector <bool> &current)
    {
        
        visited[source]=true;
        current[source]=true;
        for(int i:l[source])
        {
            if(current[i]==true){
               
                    return true;
            }
            else if(visited[i]==false)
            {
                bool check= detectDirectedCycle(i,visited,current);
                if(check)
                {
                    return true;
                }
            }
        }
        current[source]=false;
        return false;
        
    }

    
};



int main()
{
    graph g(6);
    vector <bool> visited(6,false);
    vector <bool> source(6,false);
    vector <int> parent(6,-1);
    // g.addEdge(0,1,false);
    // g.addEdge(1,2);
    g.addEdge(1,0,false);
    g.addEdge(2,1,false);
    // g.addEdge(1,2,false);
    g.addEdge(0,2,false);
    // g.addEdge(2,3,false);
    // g.print();
    // g.bfs(3,2);
    if(g.detectDirectedCycle(0,visited,source))
    {
        cout << "cycle detected";
    }
    else{
        cout<< "no cycle found";
    }
    return 0;
}
///for integer values

// now for abstract node
//cities are connected

// class graph{
//     public:
//     unordered_map<string,list<string> *> ll;
//     graph(vector<string> cities)
//     {
//         for(auto city:cities)
//         {
//             ll[city]=new list<string>;
//         }
//     }


//     void addEdge(string s,string e,bool undir=true)
//     {
//         ll[s]->push_back(e);
//         if(undir)
//         {
//             ll[e]->push_back(s);
//         }
//     }


//     void print()
//     {
//         for(auto i:ll)
//         {
//             cout << i.first<< "---";
//             for(auto j:*(i.second))
//             {
//                 cout <<j<<"--";
//             }
//             cout << endl;

//         }
//     }
// };
// class node{
//     public:
//     string cityName;
//     list<string> nbrs;
//     node(string cityName)
//     {
//         this->cityName=cityName;
//     }
 
// };
// class graph{
//     public:
//     unordered_map<string,node *> ll;
//     graph(vector<string> cities)
//     {
//         for(auto city:cities)
//         {
//             ll[city]=new node(city);
//         }
//     }


//     void addEdge(string s,string e,bool undir=true)
//     {
//         ll[s]->nbrs.push_back(e);
//         if(undir)
//         {
//             ll[e]->nbrs.push_back(s);
//         }
//     }


//     void print()
//     {
//         for(auto i:ll)
//         {
//             cout << i.first<< "---";
//             for(auto j:i.second->nbrs)
//             {
//                 cout <<j<<"--";
//             }
//             cout << endl;

//         }
//     }
// };


// int main()
// {
//     vector <string> s{"london","delhi","india","uk"};
//     graph g(s);

//     g.addEdge("india","delhi");
//     g.addEdge("uk","london");
//     g.print();
//     return 0;
// }