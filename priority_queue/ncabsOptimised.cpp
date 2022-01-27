#include <bits/stdc++.h>
using namespace std;

class Car{
    public:
    int x;
    int y;
    string id;
    Car(int x,int y,string id)
    {
        this->x=x;
        this->y=y;
        this->id=id;
    }

    int dis()
    {
        return (x*x+y*y);
    }
};


class compare{
    public:
    bool operator()(Car A,Car B)
    {
        return A.dis()<B.dis();
    }
};

void printKClosest(vector <Car> arr,int k)
{
    priority_queue <Car,vector<Car>,compare> store(arr.begin(),arr.begin()+k);

    for(int i=k;i<arr.size();i++)
    {
        auto top=store.top();
        if(arr[i].dis()<top.dis())
        {
            store.pop();
            store.push(arr[i]);
        }
    }

    while(!store.empty())
    {
        auto top=store.top();
        cout << top.id<< endl;
        store.pop();
    }
    return ;

}

int main()
{
    int n,k,x,y;
    string id;
    cin>>n>>k;
    vector<Car> arr;
     
    for(int i=0;i<n;i++)
    {
        cin>>id>>x>>y;
        Car temp(x,y,id);
        arr.push_back(temp);

    }

    printKClosest(arr,k);
    return 0;
}