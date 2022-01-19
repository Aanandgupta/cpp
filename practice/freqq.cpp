#include <bits/stdc++.h>
using namespace std;


int count(vector <int> arr,int key)
{
}
int main()
{
    vector <int> ary{0,0,0,1,1,1,1,2,2,2,3,3,4,4,5,5,5,5};
    int key;
    cin >> key;
    cout << upper_bound(ary.begin(),ary.end(),3)-lower_bound(ary.begin(),ary.end(),3);  
 
}