#include <bits/stdc++.h>
using namespace std;

class Car{
    public:
    int x;
    int y;
    string id;
    Car(string id="",int x=0,int y=0)
    {
        this->id=id;
        this->x=x;
        this->y=y;
    }
    int dis()
    {
        return x*x+y*y;
    }

};


class Compare{
    public:
    bool operator()(Car A,Car B)
    {
        return  A.dis()>B.dis();
    }
};
int main()
{
    int n,k;
    priority_queue <Car,vector<Car>,Compare> store; 
    cin >> n >>k;
    int xdis,ydis;
    string id;
    for(int i=0;i<n;i++)
    {
        cin>>id>>xdis>>ydis; 
        Car temp(id,xdis,ydis);
        store.push(temp);
    }
    while(!store.empty())
    {
        auto single=store.top();
        cout<<single.id << single.x << single.y<<endl;
        store.pop();
    }
    return 0;
}