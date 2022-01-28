#include <bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> arr{1,16,4,16,64,16};
    unordered_map <int,int> left;  
    unordered_map <int,int> right;  
    int r;
    cin>>r;

    // index.insert({arr[0],0});
    for(int i=0;i<arr.size();i++)
    {
        right[arr[i]]++;
        left[arr[i]]=0;
    }
    for(int i=0;i<arr.size();i++)
    {
        right[arr[i]]--;
        if(arr[i]%r==0 and left.find(arr[i]/r)!=left.end() and  right[arr[i]*r]>0)
        {
            for(int j=0;j<left[arr[i]/r]*right[arr[i]*r];j++)
            {
                cout << arr[i]/r << arr[i] <<arr[i]*r<< endl;
            }
        }
        left[arr[i]]++;
    }

  


    return 0;
}