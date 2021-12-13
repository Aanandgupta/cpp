#include <iostream>
#include <vector>
#include <string>
using namespace std;

void sub(string s,string cur_s,int i,int len)
{
    if(i==len)
    {
        cout << cur_s <<endl;
        return;
    }
    sub(s,cur_s+s[i],i+1,len);
    sub(s,cur_s,i+1,len);
    
}



int main()
{
    string s("abc");
    string cur_s("");

    sub(s,cur_s,0,s.size());
    return 0;
}