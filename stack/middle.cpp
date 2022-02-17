#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data=data;
        prev=NULL;
        next=NULL;
    }

};

class ll{

    public:
    Node *root;
    Node *middle;
    int size;
    ll()
    {
       root==NULL;
       middle=NULL;
      
    }
    void push(int data)
    {
        Node *temp=new Node(data);
        if(root==NULL)
        {
            root=temp;
        }
        else{
            temp->next=root;
            root->prev=temp;
            root=temp;
        }
        if(size==0)
        {
            middle=root;
        }
        else if(size%2==0)
        {
            middle=middle->next;
        }
        size+=1;
    }
    void pop()
    {
        if(root==NULL)
        {
            return ;
        }
        Node *temp=root;
        root=root->next;
        delete temp;
        if(size<=1)
        {
            middle=NULL;   
        }
        else if(size%2!=0)
        {
            middle=middle->prev;
        }
        if(size>0)
        {
            size--;
        }
    }

    int middle()
    {
        if(middle==NULL)
        {
            return -1;
        }
        return middle->data;
    }

    void deleteMiddle()
    {
        if(middle==NULL)
        {
            return;
        }
        if(size==1)
        {
            pop();
            return;
        }
        Node *temp=middle;
        Node *temp1=middle;
        if(size==2)
        {
            root=middle->next;
            delete temp1;
            middle = root;
            size--;
            return ;

        }
        if(size%2==0)
        {
            temp=middle->next;
        }
        else
        {
            temp=middle->prev;
        }

        middle->prev->next=middle->next;
        middle->next->prev=middle->prev;
        delete temp1;
        middle=temp;

    }

};



int main()
{

    return 0;
}