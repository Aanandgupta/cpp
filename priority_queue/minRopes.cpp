#include <bits/stdc++.h>
using namespace std;


int main(){


    vector <int> arr{4,3,2,6};

    priority_queue <int,vector<int>,greater<int>> store(arr.begin(),arr.begin()+arr.size());
    int sum=0,a,b;
    while(!store.empty())
    {
        a=store.top();
        store.pop();
        b=store.top();
        store.pop();
        if(!store.empty())
        {

        store.push(a+b);
        }
        sum+=a+b;
        cout << a<< b;
    }

    cout << sum;

    return 0;

}