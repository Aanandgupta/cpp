#include <iostream>
#include <vector>
using namespace std;

//given an array found width of max width moiuntain

  int longestMountain(vector<int>& arr) {
        
        int i=1,ans=0;
        while(i<arr.size()-1)
        {
            if(arr[i-1]<arr[i] and arr[i]>arr[i+1])
            {
                int x=i,j=i;
                while(x>0 and arr[x]>arr[x-1])
                {
                    x--;
                }
                while(j<arr.size()-1 and arr[j+1]<arr[j])
                {
                    j++;
                }
                ans=max(ans,j-x+1);
                i=j+1;
                    
            }
            else{
                i++;
            }
        }
        return ans;
    }
