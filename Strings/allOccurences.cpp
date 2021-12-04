#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s="khadak singh ke kadak ne se kadak ti hai";
    string word;
    getline(cin,word);
    int index=s.find(word);
    int i=0;
    while(index!=-1)
    {
        cout <<i+1 <<"occurence is at"<<index;
        index=s.find(word,index+1);
        i++;
    }
    return 0;
}