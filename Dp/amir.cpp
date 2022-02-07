#include <bits/stdc++.h>
using namespace std;

// bootom up

int minCost( vector<vector<int>> store,int n)
{

    vector<vector<int>> values;
    values.push_back({0,0,0});
    values.push_back({store[0][0],store[0][1],store[0][2]});
   for(int i=2;i<=n;i++)
   {
       int a=store[i-1][0]+min(values[i-1][1],values[i-1][2]);
       int b=store[i-1][1]+min(values[i-1][0],values[i-1][2]);
       int c=store[i-1][2]+min(values[i-1][1],values[i-1][0]);
       values.push_back({a,b,c});
   }

   return min({values[n][0],values[n][1],values[n][2]});
}

int main()
{
    int n=3;
    vector<vector<int>> store({{146,5,160},{1,9,13},{4,63,67}});
    vector<int> dp(n+1);
    cout<<minCost(store,n);
    
    return 0;
}

//top down
// int minCost( vector<vector<int>> store,int n,int x=-1)
// {
//     int ans=INT_MAX;
//     if(n<=0)
//     {
//         return 0;
//     }
//     for(int i=0;i<store[n-1].size();i++)
//     {
//         if(i!=x)
//         {
//             ans=min(ans,store[n-1][i]+minCost(store,n-1,i));
//         }
//     }
//     return ans;
// }

// int main()
// {
//     int n=3;
//     vector<vector<int>> store({{14,15,16},{11,9,13},{5,4,67}});
//     vector<int> dp(n+1);
//     cout<<minCost(store,n);
//     return 0;
// }