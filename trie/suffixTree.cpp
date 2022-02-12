

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

    void insertSuffix(string str)
    {
        for(int i=0;i<str.size();i++)
        {
            insert(str.substr(i));
        }
        
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

    Trie *trie=new Trie();
    trie->insertSuffix("anand");
    cout<<trie->search("anand");
    cout<<trie->search("ana");
    cout<<trie->search("bna");
    cout<<trie->search("cnand");
    cout<<trie->search("d");
    cout<<trie->search("nd");
    return 0;
}