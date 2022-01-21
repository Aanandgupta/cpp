#include <bits/stdc++.h>
using namespace std;

void keyPad(int n,string s,int len,int i)
{
    if(i>len)
    {
        cout << s << endl;
        return ;
    }
    int power=pow(10,len-i);
    int digit=(n/power)%10;
    //i ke all combinations
    for(int j=0;j<3;j++)
    {
        char z='A'+((3*(digit-2))+j);
        keyPad(n,s+z,len,i+1);
    }
}

int main()
{
    string s="";
    int n=23;
    keyPad(n,s,floor(log10(n))+1,1);
    return 0;
}