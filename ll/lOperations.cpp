#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

void InsertAtHead(node * &head,int data)
{
    node *temp=new node(data);
    // if(head==NULL)
    // {
    //     head=temp;
    //     return;
    // }
    temp->next=head;
    head=temp;
    return;
}


void print(node *head)
{
    while (head!=NULL)
    {
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
    
}


void InsertAtMid(node * &head,int data,int pos)
{
    if(pos==0)
    {
        InsertAtHead(head,data);
        return;
    }
    node *temp=head;
    for(int jump=1;jump<=pos-1 && temp!=NULL;jump++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        cout << "Invalid Position";
        return ;
    }
    node *temp2=new node(data);
    temp2->next=temp->next;
    temp->next=temp2;
    return ;
}



void InsertAtEnd(node * &head,int data)
{
    node *temp=new node(data);
    if(head==NULL)
    {
        head=temp;
        return ;
    }
    node *iterate=head;
    while (iterate->next!=NULL)
    {
        iterate=iterate->next;
    }
    iterate->next=temp;

    // return iterate;
}


void deleteAtHead(node * &head)
{
    if(head==NULL)
    return ;
    node * toDelete=head;
    head=head->next;
    delete toDelete;
    return ;

}

void deleteAtEnd(node * &head)
{
    if(head==NULL)
    return ;
    node *temp=head;
    if(head->next==NULL)
    {
        head=NULL;
        delete temp;
        return;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }

    node *temp1=temp->next;
    temp->next=NULL;
    delete temp1;
    return;
}

void deleteAtMid(node* &head,int pos)
{
    if(head==NULL)
    {
        return ;
    }
    if(pos==0)
    {
        deleteAtHead(head);
        return;
    }
    node *temp=head;
    for(int jump=1;jump<=pos-1 && temp->next!=NULL;jump++)
    {
        temp=temp->next;
    }

    if(temp->next==NULL)
    return ;
    node *temp1=temp->next;
    temp->next=temp->next->next;
    delete temp1;

}

int main()
{
    node *head=NULL;
  
    InsertAtEnd(head,33);
    // InsertAtEnd(head,34);
    InsertAtMid(head,36,1);
    InsertAtMid(head,35,1);
    InsertAtMid(head,37,1);
    InsertAtMid(head,38,1);
    print(head);
    deleteAtEnd(head);
    print(head);

    return 0;
}