
// bottom up

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> store(amount+1);
//         store[0]=0;
//         for(int i=1;i<=amount;i++)
//         {
//             int temp=INT_MAX;
//             for(int j:coins)
//             {
//                 if(i-j>=0 and store[i-j]!=INT_MAX)
//                 {
//                    temp=min(temp,store[i-j]+1); 
//                 }
                
//             }
            
//             store[i]=temp;
//         }
        
//         return store[amount]==INT_MAX?-1:store[amount];
        
//     }
// };




//top down
#include <bits/stdc++.h>
using namespace std;


int minCount(vector<int> coins,int target,int count)
{
    int ans=INT_MAX;
    if(target==0)
    {
        return count;
    }
    if(target<0)
    {
        return INT_MAX;
    }
    for(auto i:coins)
    {
        ans=min(ans,minCount(coins,target-i,count+1));
    }
    return ans;
}

int main()
{ 
    vector<int> coins{1,3,7,10};
    int target=14;
    cout<<minCount(coins,target,0);
    return 0;
}