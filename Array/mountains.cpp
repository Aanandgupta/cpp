#include <iostream>
#include <vector>
using namespace std;

//given an array found width of max width moiuntain
int main()
{
    vector<int> heights={5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    int i=1,l=0,r=0,j=0,maxWidth=-1;
    cout << heights.size();
    while(i<heights.size()-1)
    {
        if(heights[i-1]<heights[i] && heights[i]>heights[i+1])
        {
            j=i+1;
            maxWidth=max(maxWidth,j-l);
            while(j+1 <heights.size() && heights[j]>heights[j+1])
            {
                j++;
            }
            maxWidth=max(maxWidth,j-l);
            l=j;
            i=j;
        }
        i++;
    }

    cout << maxWidth;
    return 0;
}