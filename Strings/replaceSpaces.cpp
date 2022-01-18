#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    char in[90];
    string token;
    getline(cin,s);
    stringstream ss(s);
    vector <string> sss;
    char*temp =strtok(s," ");
    while(getline(ss,token,','))
    {
        sss.push_back(token);
    }
    sss.size();
    for(int i=0;i<sss.size();i++)
    {
        cout << sss[i];
    }

}