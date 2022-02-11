#include <bits/stdc++.h>
using namespace std;


int possible(vector <int> arr,int value,int birds)
{
    int count=1,j=0;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]-arr[j]>=value)
        {
            count++;
            j=i;
            if(count==birds)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    vector <int>  arr{1,2,4,8,9};
    int n=5,b=2,i=0,j,mid;
    int min=arr[n-1]-arr[0];
    j=min;
    int ans=-1;
    while(i<=j)
    {
        // cout << mid << endl;
        mid=(i+j)/2;
        if(possible(arr,mid,b))
        {
            ans=mid;
            i=mid+1;
        }
        else{
            j=mid-1;
        }

    }
    cout << ans;
    
    return 0;
}