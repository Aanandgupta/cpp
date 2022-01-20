#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,p,i=0,j,mid,fractionalPart,x;
    float integerPart,h;
    cin >> k;
    cin >> p;
    j=k;
    while(i<=j)
    {
        mid=i+(j-i)/2;
        if(mid*mid<=k)
        {
            integerPart=mid;
            i=mid+1;
        }
        else{
            j=mid-1;;
        }
    }
    h=0.1;
    for(i=1;i<=p;i++)
    {
        while((integerPart)*(integerPart)<=k)
        {
            integerPart+=h;
        }
        integerPart-=h;
        h=h/10.0;
    }
    // j=pow(10,p);
    // x=1/j;
    // j=(j-1)/j;
    // i=0;
    // k=k-integerPart;
    //  while(i<=j)
    // {
    //     mid=i+(j-i)/2;
    //     if((mid-x)*(mid-x)<1 &&(mid+x)*(mid+x)>1)
    //     {
    //         fractionalPart=mid;
    //         break;
    //     }
    //     else if(mid*mid>k)
    //     {
    //         j=mid-x;
    //     }
    //     else{
    //         i=mid+x;
    //     }
    // }
    cout << integerPart;
    return 0;
}