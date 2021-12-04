#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    string token;
    getline(cin,s);
    stringstream ss(s);
    vector <string> sss;
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