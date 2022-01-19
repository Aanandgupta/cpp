#include <bits/stdc++.h>
using namespace std;



void merge(vector <int> &a,int l,int mid,int r)
{
    vector <int> arr1,arr2;
    int x=l,y=mid+1,j=0;;
    while(x<=mid && y<=r)
    {
        if(a[x]<a[y])
        {
            arr1.push_back(a[x++]);
        }
        else{
            arr1.push_back(a[y++]);
        }
    }
    while(x<=mid)
    {
        arr1.push_back(a[x++]);
    }
    while(y<=r)
    {
        arr1.push_back(a[y++]);
    }

    for(x=l;x<=r;x++)
    {
        a[x]=arr1[j++];
    }

    return ;


}

void mergeSort(vector <int> &a,int l,int r)
{
    int mid=(l+r)/2;
    if(l>=r)
    {
        return ;
    }
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
    merge(a,l,mid,r);
    return;
}

int main()
{

    vector <int> a;
    int i,temp=0;
    cin >> i;
    for(int x=0;x<i;x++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    for(int x=0;x<i;x++)
    {
        cout << a[i];
    }

    mergeSort(a,0,i-1);

    for(int x=0;x<i;x++)
    {
        cout << a[i];
    }

    return 0;
}