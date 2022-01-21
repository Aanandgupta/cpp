#include <bits/stdc++.h>
using namespace std;



int search(vector <string> arr,string s)
{
    int i=0,j=arr.size()-1,mid,l,r;
     while(i<=j)
    {
        mid=(i+j)/2;
        // cout << mid;
            l=mid-1;
            r=mid+1;
        if(arr[mid]=="")
        {
            // cout << l;
           while(1)
           {
               if(l<i && r>j)
               {
                   return -1;
               }
               else if(l>=i && arr[l]!="")
               {
                   cout <<l;
                   mid=l;
                   break;
               }
               else if(r<=j && arr[r]!="")
               {
                   mid=r;
                   break;
               }
               l--;
               r++;
           }
        }
        if(arr[mid]==s)
        {
            return mid;
        }
        else if(arr[mid]>s)
        {
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }

    

    return -1;
}

int main()
{
    vector <string> arr{"","aba","abc","","anand","",""};
    int i=0,j=arr.size()-1,mid,x=1,h,k;
    string s="aba";
    cout << search(arr,s);

    return 0;
}