
#include <bits/stdc++.h>
using namespace std;



class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector <int> store(n+1);
        store[0]=0;
        for(int j=1;j<=n;j++)
        {
            store[j]=price[j-1];
            for(int i=1;i<=j/2;i++)
            {
                if(j-i>=0)
                {
                   store[j]=max(store[j],store[j-i]+store[i]); 
                }
            }
        }
        
        return store[n];
       
    }
};