#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> arr={3, 1, 2, 2, 1, 2, 3, 3},result;
    int max=*max_element(arr.begin(),arr.end()),k=4;
    vector <int> ary(max+1,0);
    for(int i=0;i<arr.size();i++)
    {
        ary[arr[i]]+=1;
    }
    for(int i=1;i<=max;i++)
    {
        if(ary[i]!=0)
        {
            if(ary[i]>(arr.size()/k))
            {
                result.push_back(i);
            }
        }
    }

    for(int i:result)
    {
        cout << i <<" ";
    }

    return 0;
}