#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> c={0,1,0,2,1,0,1,3,2,1,2,1};
    int n=c.size(),i,total=0;
    vector <int> prefix(n,0),suffix(n,0);
    prefix[0]=c[0];
    for(i=1;i<c.size();i++)
    {
        prefix[i]=(max(c[i],prefix[i-1]));
    }
    suffix[n-1]=c[n-1];
    for(i=c.size()-2;i>0;i--)
    {
        suffix[i]=(max(c[i],suffix[i+1]));
    }
     for(i=1;i<c.size();i++)
    {
        total+=min(prefix[i],suffix[i])-c[i];
    }

    cout<<total;


    return 0;
}