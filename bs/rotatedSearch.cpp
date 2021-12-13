#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> ary{7,9,10,1,2,3,4,5,6};
    int i=0,j=ary.size()-1,mid=0,e=ary.size()-1,x=0;
    int key=2;
    while(i<=j)
    {
        mid=(i+j)/2;
        if(ary[mid]==key)
        {
            cout << mid;
            x=1;
            break;

        }
        if(ary[mid]<=ary[e])
        {
            if(ary[mid]<=key && key<=ary[e])
            {
                // left
                j=mid-1;
            }
            else{
                //right
                i=mid+1;

            }
        }
        else
        {
            if(ary[mid]>=key && ary[0]<=key)
            {
                //right
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }

    }

    if(!x)
    {
        cout << "not found";
    }

    return 0;
}