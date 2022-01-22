#include <bits/stdc++.h>
using namespace std;





int main()
{
    string s="aabccbcd",output="";
    vector <int> count(256,0);
    queue <char> store;


    for(int i=0;i<s.size();i++)
    {
        if(count[s[i]]==0)
        store.push(s[i]);
        
        count[s[i]]+=1;

       
         while(store.empty() !=true && count[store.front()]!=1)
            {
                store.pop();
            }
        if(store.empty())
        cout << "-1";
        else
        cout << store.front();

    }

    cout << output;

    return 0;

}