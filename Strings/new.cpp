#include <bits/stdc++.h>
using namespace std;



void build(int a,vector<int> arr,unordered_map <int,int> &arr1)
{
    arr1[1]=a;
    for(int i=0;i<a;i++)
    {
        int temp=arr[i];
        if(arr1.find(temp)!=arr1.end())
        {
            arr1[temp]+=1;
        }
        else{
            arr1[temp]=1;
        }
        int temp2=2;
        while(temp2*temp2<=temp)
        {
            if(temp%temp2==0)
            {
                 if(arr1.find(temp2)!=arr1.end())
                {
                    arr1[temp2]+=1;
                }
                else{
                    arr1[temp2]=1;
                }
                
                if((temp2*temp2!=temp))
                  {
                       if(arr1.find(temp/temp2)!=arr1.end())
                        {
                            arr1[temp/temp2]+=1;
                        }
                        else
                        {
                            arr1[temp/temp2]=1;
                        }
                   }
              
            }
        temp2+=1;
        
    }
    }
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a,b,c,d;
    vector <int> arr;
    vector <int> arr2;
    unordered_map<int, int> arr1;
    cin >> a;
    for(int i=0;i<a;i++)
    {
        cin >> b;
        arr.push_back(b);
    }
    cin >> c;
    for(int j=0;j<c;j++)
    {
        cin >> d;
        arr2.push_back(d);
    }
    build(a,arr,arr1);
    for(int j=0;j<c;j++)
    {
        d=arr2[j];
        if(arr1.find(d)!=arr1.end())
        {
            cout << arr1[d] << endl;
        }
        else{
            cout << 0 ;
        }
       
    }
    return 0;
}
