#include <bits/stdc++.h>
using namespace std;


int pivotIndex(vector <int> arr1,int i,int j)
{
    int l=j;
    i=i-1;
    int element=arr1[j];
    while(i<j)
    {
        do{
            i++;
        }
        while(arr1[i]<=element);
        do{
            j--;
        }
        while(arr1[j]>element);
        if(i<j)
        {
            swap(arr1[i],arr1[j]);
        }
    }
    swap(arr1[i],arr1[l]);
    return i;

}
int main()
{
    int k;
    vector <int> arr1{2,3,4,5,6,1};
    cin >> k;
    int i=0,j=arr1.size()-1;
    int pivot=pivotIndex(arr1,0,j);
    while(pivot!=k)
    {
        if(pivot>k)
        {
            j=pivot-1;
        }
        else 
        {
            i=pivot+1;
        }
        pivot=pivotIndex(arr1,i,j);
    }
    cout << pivot;

    return 0;
}