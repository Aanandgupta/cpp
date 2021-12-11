#include <iostream>
#include <vector>
#include <string>
using namespace std;


int climbing(int s,int n)
{
    if(s>=n)
    {
        return 0;
    }
    return (3+climbing(1,n)+climbing(2,n)+climbing(3,n));
}



int main()
{

    return 0;
}