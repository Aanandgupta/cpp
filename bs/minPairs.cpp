#include <bits/stdc++.h>
using namespace std;
//keval lower bound se bhi kam ho jata
int main()
{
    vector<int> arr1{2,3,4,5,6},arr2{13,14,15,57};
    vector <int>::iterator l,u;
    int minimum=10000;
    for(int i=0;i<arr1.size();i++)
    {
        l=lower_bound(arr2.begin(),arr2.end(),arr1[i]);
        u=upper_bound(arr2.begin(),arr2.end(),arr1[i]);
        if(l-u==0)
        {
            if(l-arr2.begin()==0)
            {
                minimum=(arr2[0]-arr1[i]<minimum?arr2[0]-arr1[i]:minimum);
            }
            else if(l-arr2.begin()==arr2.size()){
                minimum=(arr1[i]-arr2[arr2.size()-1]<minimum?arr1[i]-arr2[arr2.size()-1]:minimum);
            }
            else{
                minimum=(arr1[i]-arr2[l-arr2.begin()-1]<minimum?arr1[i]-arr2[l-arr2.begin()-1]:minimum);
                minimum=(arr2[u-arr2.begin()]-arr1[i]<minimum?arr2[u-arr2.begin()]-arr1[i]:minimum);
            }
        }
        else
        {
            cout << arr1[i] << arr2[i];
        }
    }

    cout << minimum;
    return 0;
}