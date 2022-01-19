#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector <int> ary{2,2,2,2,3,4,4,4,4,4,5,6,7,7,7};
    int n=4,i=0,j=ary.size()-1,mid=0,lower=0,upper=0;
    while(i<=j)
    {
        mid=(i+j)/2;
        if(ary[mid]==n && (mid==0 || ary[mid-1]<ary[mid]))
        {
         lower=mid; 
         break;
        }
        else if(ary[mid]<n)
        {
            
            i=mid+1;
        }
        else{
            j=mid-1;
        }

    }
    i=0,j=ary.size()-1;
    while(i<=j)
    {
        mid=(i+j)/2;
        if(ary[mid]==n && (mid==ary.size()-1 || ary[mid+1]>ary[mid]))
        {
         upper=mid; 
         break;
        }
        else if(ary[mid]>n)
        {
            j=mid-1;
        }
        else{
            i=mid+1;
        }

    }
    if(!upper&&!lower)
    {
        cout << 0;
    }
    else{
        
    cout << (upper-lower+1);
    }
    return 0;

}