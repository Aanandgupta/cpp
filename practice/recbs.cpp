#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector <int> ary,int l,int r,int key)
{
    if(l>r)
    return -1;
    int mid=l+(r-l)/2;
    if(ary[mid]==key)
    return mid;
    if(ary[mid]>key)
    return binarySearch(ary,l,mid-1,key);
    return binarySearch(ary,mid+1,r,key);
}

int main()
{
    vector <int> ary{1,2,2,3,4,35,4,56,6,5};
    sort(ary.begin(),ary.end());
    cout << binarySearch(ary,0,ary.size()-1,4);

    return 0;
}