#include <bits/stdc++.h>
using namespace std;


void subsequence(string input,string output)
{
    if(input.empty())
    {
        cout << output << "    ";
        return;
    }
    subsequence(input.substr(1),output+input[0]);
    subsequence(input.substr(1),output);
    return ;
}

int main()
{
    subsequence("aaa","");
    return 0;
}