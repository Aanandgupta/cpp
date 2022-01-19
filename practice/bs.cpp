#include <bits/stdc++.h>
using namespace std;


int main()
{
    //itterartive
    vector <int> a;
    int n,key;
    int mid,temp;
    cin >> n;
    cin >> key;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    int i=0,j=n-1;
    while(i<=j)
    {
        mid=i+(j-i)/2;
        if(a[mid]==key)
        {
            cout << key <<"found" ;
            break;
        }
        else if(a[mid]>key)
        {
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }

    if(i>j)
    cout << "Not found";
    return 0;
}