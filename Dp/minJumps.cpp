#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> store(nums.size(),-1);
        store[0]=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            
            for(int j=1;j<=nums[i] and i+j < nums.size();j++)
            {
                if(store[i+j]!=-1)
                {
                    store[i+j]=min(store[i]+1,store[i+j]);
                }
                else{
                    store[i+j]=store[i]+1;
                }
            }
        }
        
        return store[nums.size()-1];
    }
};