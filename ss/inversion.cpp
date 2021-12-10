#include <iostream>
#include <vector>
using namespace std;





int crossInversions(vector <int> &ary,int s,int e)
{
    int mid =(s+e)/2;
    int i=s,j=mid+1;
    int count=0,k=0;
    vector <int> temp;
    while(i<=mid and j<=e)
    {
        if(ary[i]<=ary[j])
        {
            temp.push_back(ary[i++]);
        }
        else{
            count+=mid-i+1;
            temp.push_back(ary[j++]);
        }
    }

    while(i<=mid)
    {
        temp.push_back(ary[i++]);
    }
    while(j<=e)
    {
        temp.push_back(ary[j++]);
    }
    for(int x=s;x<=e;x++)
    {
        ary[x]=temp[k++];
    }

    return count;

}

int countInversion(vector <int> &ary,int s,int e)
{
    if(s>=e)
    {
        return 0;
    }
    int mid=(s+e)/2;
    return (countInversion(ary,s,mid)+countInversion(ary,mid+1,e)+crossInversions(ary,s,e));


}
int main()
{
    vector <int> ary{2,33,45,74,34,2,46,9};
    int n=ary.size()-1;
    cout << countInversion(ary,0,n);
    

    return 0;
}