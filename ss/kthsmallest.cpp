#include <bits/stdc++.h>
using namespace std;


int pivotIndex(vector <int> &arr1,int i,int j)
{
    int l=j;
    i=i-1;
    int element=arr1[j];
    while(i<j)
    {
        do{
            i++;
        }
        while(arr1[i]<element);
        do{
            j--;
        }
        while(arr1[j]>=element);
        if(i<j)
        {
            swap(arr1[i],arr1[j]);
        }
    }
    swap(arr1[i],arr1[l]);
    return i;

}


int  qsort(vector <int> &arr1,int i,int j,int k)
{
     int pivot=pivotIndex(arr1,0,j);
    //  pivot=pivotIndex(arr1,0,j);
    //  pivot=pivotIndex(arr1,0,j);
     if(pivot==k)
     {
        return arr1[pivot];
     }
     if(k<pivot)
     {
        
        return qsort(arr1,i,pivot-1,k);
     }
     else{
        return qsort(arr1,pivot+1,j,k);
     }
    return pivot;
}
int main()
{
    int k=5;
    vector <int> arr1{3,2,1,5,6,4};
    int i=0,j=arr1.size()-1;
    cout<<qsort(arr1,0,j,k);
    for (int i:arr1)
    {
       cout<<i; 
    }
    
    return 0;
}