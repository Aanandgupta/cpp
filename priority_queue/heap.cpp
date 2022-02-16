#include <bits/stdc++.h>
using namespace std;



class Compare{
    public:
   bool operator()(int a,int b)
    {
    return a>b;
    }
};
int main()
{

    vector <int> arr{2,3,32,3,2,24,4,44,5};
    priority_queue<int,vector<int>,Compare> a;
    for(int i:arr)
    {
        a.push(i);
    }

    while(!a.empty())
    {
        cout<<a.top()<<" ";
        a.pop();
    }
    return 0;
}