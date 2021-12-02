#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int j,i,count=-1;
    vector <int> bands={1,9,3,0,18,5,2,4,10,7,12,6};
    unordered_set <int> band;
    for(int i:bands)
    {
        band.insert(i);
    }
    for(int i=0;i<bands.size();i++)
    {
        if(band.find(bands[i]-1)==band.end())
        {
            j=1;
            while(band.find(bands[i]+j)!=band.end())
            {
                j++;
            }
            count =max(count,j);

        }
    }
    cout << count;
    return 0;
}