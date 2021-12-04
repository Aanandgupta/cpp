//longest substring to make the array sorted

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> ary={1,2,3,4,5,8,6,7,9,10,11};
    int smallest=100000,largest=-1,n=ary.size();
    int i,j;
    if(ary[0]>ary[1])
    {
        smallest=min(smallest,ary[0]);
        largest=max(largest,ary[0]);
    }
    if(ary[n-1]<ary[n-2])
    {
        smallest=min(smallest,ary[0]);
        largest=max(largest,ary[0]);
    }

    for(i=1;i<n-1;i++)
    {
        if(ary[i]<ary[i-1] || ary[i]>ary[i+1])
        {
            smallest=min(smallest,ary[i]);
            largest=max(largest,ary[i]);
        }
    }

    for(j=n-1;j>=0;j--)
    {
        if(largest>ary[j])
        {
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        if(smallest<ary[i])
        {
            break;
        }
    }

    cout << i << j;

    return 0;
}