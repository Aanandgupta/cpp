#include <bits/stdc++.h>
using namespace std;

class index
{
    public:
    int x,y,z;
    index(int a,int b,int c)
    {
        x=a;
        y=b;
        z=c;
    }
};

class compare{
    public:
    bool operator()(index A,index B)
    {
        return(A.x>B.x);
    }
};
int main()
{
    vector<vector<int>> arr{{3,5,6},{1,2,4,5,6,7},{5,7,9}};
    priority_queue <index,vector<index>,compare> arr1;
    cout<<arr[0].size();
    for(int i=0;i<arr.size();i++)
    {
        index temp(arr[i][0],i,0);
        arr1.push(temp);
    }

    while(!arr1.empty())
    {
        auto temp1=arr1.top();
        arr1.pop();
        cout <<temp1.x<<endl;
        if(temp1.y<arr.size() && temp1.z<arr[temp1.y].size()-1)
        {
            index temp2(arr[temp1.y][temp1.z+1],temp1.y,temp1.z+1);
            arr1.push(temp2);
        }

    }
    return 0;
}