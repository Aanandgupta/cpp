// given an array adn number find all three distinct pirs such that their sum=number the pairs are in asscending order 
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;


int main()
{
    int quantity=0,temp=0;
    vector <int>ary;
    vector <vector<int>> result;
    int total=0,target;
    int i,j;
    cout<<"Enter Number OF Elements";
    cin>>quantity;
    cout<<"Enter Number";
    cin>>total;
    for(i=0;i<quantity;i++)
    {
        cin >> temp;
        ary.push_back(temp);
    }
    sort(ary.begin(),ary.end());
    for(int k=0;k<quantity-2;k++)
    {
        i=k+1;j=ary.size()-1;
        while(i<j)
        {
            target=ary[i]+ary[j];
            if(target==total-ary[k])
            {
                result.push_back({ary[k],ary[i],ary[j]});
                i++;
                j--;
            }
            else if(target>total-ary[k])
            j--;
            else
            i++;
        }
    }
    for(i=0;i<result.size();i++)
    {
        for(
            
        )
        {
            cout << num;
        }
        cout << endl;
    }

    return 0;
}

//with set approach we were using extra space of O(n) but here we are not we cant use this method in two pointer