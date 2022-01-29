// select two numbers such that thier sum is equal to n given that atleast one such pair exists nlogn approach 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> towSum(vector<int> s,int num)
{
    int i=0,j=s.size()-1;
    int target;
    vector<int> ind;  
    sort(s.begin(),s.end());
    while(target!=num)
    {
        if(target>num)
        j--;
        else
        i++;
        target=s[i]+s[j];
    }
    ind={s[i],s[j]};
    return ind;
} 

int main()
{
    vector<int> sum={10,5,2,3,-6,9,11};
    vector<int> ind=towSum(sum,4);
    cout << ind[0] << ind[1];
    return 0;
}