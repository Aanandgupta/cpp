/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void merge(vector <int> &aray,int s,int e)
{
    int mid=s+(e-s)/2,i=s,k=0;
    int j=mid+1;
    vector <int> temp;
    while(i<=mid and j<=e)
    {
        if(aray[i]>=aray[j])
        {
            temp.push_back(aray[j]);
            j++;
        }
        else{
            temp.push_back(aray[i]);
            i++;
        }
    }   


    while(i<=mid)
    {
        temp.push_back(aray[i++]);
    }
    while(j<=e)
    {
        temp.push_back(aray[j++]);
    }

    for(int x=s;x<=e;x++)
    {
        aray[x]=temp[k++];
    }
    return;

}
void mergeSort(vector <int> &ary,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=(s+e)/2;
    mergeSort(ary,s,mid);
    mergeSort(ary,mid+1,e);
    merge(ary,s,e);
    return;

}

int main()
{
    vector <int> ary{10,2,3,5,7,1,4};
    int n=ary.size()-1;
    mergeSort(ary,0,n);
    for(int i=0;i<=n;i++)
    {
        cout <<ary[i];
    }
    return 0;
}
