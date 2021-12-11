#include <iostream>
#include <vector>
#include <string>
using namespace std;


int countSubset(vector <int> arr,int i,int sum,int size)
{
    if(i==size)
    {
        if(sum==0)
        {
            return 1;
        }
        return 0;
    }
    int a=countSubset(arr,i+1,sum-arr[i],size);
    int b=countSubset(arr,i+1,sum,size);

    return (a+b);
}


int main()
{
    vector <int> arr{1,2,3,4,5};
    int sum=6;
    cout << countSubset(arr,0,sum,arr.size());

    return 0;
}