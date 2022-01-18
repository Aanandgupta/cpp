#include <bits/stdc++.h>
using namespace std;

char * mystrtok(char *s,char delim)
{
    static char *s1;
    int i=0;
    if(s!=NULL)
    {
        s1=s;
    }
    if(s1==NULL)
    {
    return NULL;
    }
    char *token=new char[strlen(s)+1];
    cout << s1[i] <<"de"<<endl;
    for(;s1[i]!='\0';i++)
    {
        // cout << s1[i] << "dekhp" << endl;
        if(s1[i]!=delim)
        {
            token[i]=s1[i];
        }
        else{
            token[i]='\0';
            s1=s1+i+1;
            return token;
        }
    }

    token[i]='\0';
    s1=NULL;
    return token;
}

int main()
{
    // char c[100];
    // cin.getline(c,100);
    // char *temp=strtok(c," ");
    // while(temp!=NULL)
    // {
    //     cout << temp << endl;
    //     temp=strtok(NULL," ");
    // }
    // cout << c;

    // string s;
    // getline(cin,s);
    // stringstream ss(s);
    // string token;
    // while(ss >> token)
    // {
    //     cout << token << endl;
    // }

    char s[1000];
    cin.getline(s,1000);
    char *tok=mystrtok(s,' ');
    while(tok!=NULL)
    {
        cout << tok << endl;
        tok=mystrtok(NULL,' ');
        cout << "vjv";

    }

    return 0;
}