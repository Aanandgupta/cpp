#include <iostream>
#include <vector>
#include <string>
using namespace std;


void printBrackets(string output,int n,int open,int close,int i)
{
    if(i==2*n)
    {
        cout << output;
        return ;
    }
    if(open<n)
    printBrackets(output+'(',n,open+1,close,i+1);
    if(close<open)
    printBrackets(output+')',n,open,close+1,i+1);
}


int main()
{
    int n;
    string output;
    cin >> n;
    printBrackets(output,n,0,0,0);


    return 0;
}