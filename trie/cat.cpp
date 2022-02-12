

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    char data;
    unordered_map <char,Node*> store;
    bool isTerminal;
    
    Node(char data)
    {
        this->data=data;
        isTerminal=false;
    }

};


class Trie
{
    public:
    Node *root;
    Trie()
    {
        root=new Node('\0');
    }

    void insert(string str)
    {
        Node *temp=root;
        for(char i:str)
        {
            if(temp->store.find(i)==temp->store.end())
            {
                Node *temp2=new Node(i);
                temp->store[i]=temp2;
            }
            temp=temp->store[i];
        }
        temp->isTerminal=true;
    }

    bool search(string str)
    {
        Node *temp=root;
        for(char i:str)
        {
            if(temp->store.find(i)==temp->store.end())
            {
                return false;
            }
            temp=temp->store[i];
        }
        return temp->isTerminal;
    }
};


int main()
{
    string s="little cute cat loves to code in c++&java";
    Trie *trie=new Trie();
    vector<string> s1{"cute","cat","tle","quick","big","cute cat"};
    unordered_set <string> check;
    for(string t:s1)
    {
        trie->insert(t);
    }
    for(int i=0;i<s.size();i++)
    {
        int j=i;
        Node *temp=trie->root;
        while(j<s.size() and temp->store.find(s[j])!=temp->store.end())
        {
            if(temp->isTerminal)
            {
                check.insert(s.substr(i,j-i));
            }
            temp=temp->store[s[j]];
            j++;
        }
        if(i!=j and temp->isTerminal)
        {
            check.insert(s.substr(i,j-i));
        }
    }

    for(string s2:s1)
    {
        if(check.find(s2)!=check.end())
        {
            cout<<"FOUND ";
        }
        else{
            cout<<"NOT FOUND ";
        }
    }

    return 0;
}