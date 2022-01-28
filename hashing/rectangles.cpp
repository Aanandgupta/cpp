#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int>> arr{{0,0},{1,1},{1,0},{0,1},{2,1},{2,0},{3,0},{3,1}};
    set <pair<int,int>> store(arr.begin(),arr.end());


    int ans=0;
   for(int i=0;i<arr.size()-1;i++)
   {
       for(int j=i+1;j<arr.size();j++)
       {
           if(arr[j].first==arr[i].first or arr[j].second==arr[i].second)
           {
               continue;
           }
           if(store.find({arr[i].first,arr[j].second})!=store.end() && store.find({arr[j].first,arr[i].second})!=store.end())
           {

               ans+=1;
           }

       }
   }

    cout << ans/2;

    return 0;

}