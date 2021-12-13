#include <iostream>
#include <vector>
#include <string>
using namespace std;



int climbing(int s,int n)
{
    if(s==n)
    {
        return 1;
    }
    else if(s>n)
    {
        return 0;
    }
    return (climbing(s+1,n)+climbing(s+2,n)+climbing(s+3,n));
}



int main()
{
    int count=0;

    cout << climbing(0,4);

    return 0;
}