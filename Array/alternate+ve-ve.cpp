#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> ary={-2,4,6,7-9,-6,6,-9,-89,-90,232};
    int i=-1,neg=0,pos=0;
    int j=ary.size();
    int temp=0;
    while(i<j)
    {
        do{
            i++;
        }while(ary[i]<0);
        do{
            j--;
        }while(ary[j]>0);
        if(i<j)
        {
        temp=ary[j];
        ary[j]=ary[i];
        ary[i]=temp;
        }
    }

    for(int cur:ary)
    {
        if(cur<0)
        {
            neg++;
        }
        else{
            pos++;
        }
    }
    
    return 0;
}