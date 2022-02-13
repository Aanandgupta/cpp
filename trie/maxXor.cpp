

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
    int maxXor=INT_MIN;
    Trie *trie=new Trie();
    vector<int> a={3,10,5,25,8,2};
    Node *temp1;
    string maxstr;
    trie->insert(bitset<8>(a[0]).to_string());
    for(int k=1;k<a.size();k++)
    {
        maxstr="";
        temp1=trie->root;
        for(char i:bitset<8>(a[k]).to_string())
        {
            if(i=='1')
            {
                if(temp1->store.find('0')!=temp1->store.end())
                {
                    maxstr+='0';
                    temp1=temp1->store['0'];
                }
                else{
                    maxstr+='1';
                    temp1=temp1->store['1'];
                }
            }
            else{
                
                if(temp1->store.find('1')!=temp1->store.end())
                {
                    maxstr+='1';
                    temp1=temp1->store['1'];
                }
                else{
                    maxstr+='0';
                    temp1=temp1->store['0'];
                }
            }
        }
        int value=bitset<8>(maxstr).to_ulong();
        maxXor=max(maxXor,a[k]^value);
        trie->insert(bitset<8>(a[k]).to_string());
    }
    cout<<maxXor;

    return 0;
}