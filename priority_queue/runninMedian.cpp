#include <bits/stdc++.h>
using namespace std;

int main()
{
    //2 3 5 7
    int n,a,minimum,size1,size2;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    priority_queue<int> max_heap;
    cin >> n;   
    
    int median=INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        size1=max_heap.size();
        size2=min_heap.size();

           if(size1==size2)
            {
                if(a<median)
                {
                    max_heap.push(a);
                    median=max_heap.top();
                }
                else{
                    min_heap.push(a);
                    median=min_heap.top();
                }
            }
            else if(size1>size2)
            {
                 if(a<median)
                {
                    int temp=max_heap.top();
                    max_heap.pop();
                    min_heap.push(temp);
                    max_heap.push(a);
                }
                else{
                    min_heap.push(a);
                }

            median=(max_heap.top()+min_heap.top())/2.0;
            }
            else{
                if(a>median)
                {
                    int temp=min_heap.top();
                    min_heap.pop();
                    min_heap.push(a);
                    max_heap.push(temp);
                }
                else{
                    max_heap.push(a);
                }
            median=(max_heap.top()+min_heap.top())/2.0;
            }

            cout << median;
    }
    return 0;
}