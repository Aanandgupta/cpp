#include <bits/stdc++.h>
using namespace std;

bool compareInterval(string i1, string i2)
{
    if(i1+i2<=i2+i1)
    return true;
    return false;
}
int main()
{
    vector <string> arr{"a","aba","ab"};
    sort(arr.begin(),arr.end(),compareInterval);
    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i];
    }

    return 0;
}