#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> arr{7,8,9,10,1,2,3,4,5};
    int key,i=0,j=arr.size()-1,mid;
    cin >>key;
    if(key>arr[j])
    {
        while(i<=j)
        {
            mid=i+(j-i)/2;
            if(arr[mid]==key)
            {
                cout << mid ;
                break;
            }
            else if(arr[mid]>key || (arr[mid]<arr[arr.size()-1]) )
            {
                j=mid-1;
            }
            else {
                i=i+1;
            }
        }

    }
    else{
         while(i<=j)
        {
            mid=i+(j-i)/2;
            if(arr[mid]==key)
            {
                cout << mid ;
                break;
            }
            else if(arr[mid]<key || (arr[mid]>arr[arr.size()-1]) )
            {
                i=mid+1;
            }
            else {
                j=mid-1;
            }
        }

    }
    
    return 0;

}