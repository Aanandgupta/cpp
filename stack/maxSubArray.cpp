#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> arr{1,2,3,4,3,4,5,6,2,3,4,7};
    int k=3,i=0;
    priority_queue <int> subArray;
    for(;i<k;i++)
    {
        subArray.push(arr[i]);
    }
    for(i=i-1;i<arr.size();i++)
    {
        cout << subArray.top();
        
    }
    return 0;
}