#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector <int> arr{10,5,6,3,8,4};
    vector <bool> visited(6,false);
    map <int,int> arr1;
    for(int i=0;i<arr.size();i++)
    {
        arr1[arr[i]]=i;
    }
    int swaps=0;
    int count=0;
    int i=0;
    for(auto it:arr1)
    {
        if(!visited[i])
        {
            if(it.first!=arr[i])
            {
                int temp=it.first;
                temp=arr[arr1[temp]];
                while(temp!=it.first)
                {
                    count+=1;
                    temp=arr[arr1[temp]];
                }
            }
        }
        swaps+=count;
    }

    return 0;
}