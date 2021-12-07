#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector <int> arr{1,3,2,1,4,1,3,2,1,1,2};
    int n=arr.size(),i=0,j=0,sum=0,target=8;
    while(j<n)
    {
        sum+=arr[j];
        j+=1;
        while(sum>target && i<j)
        {
            sum-=arr[i];
            i+=1;
        }
        if(sum == target){
             cout << i <<','<< j-1;
        }
    }
    return 0;
}