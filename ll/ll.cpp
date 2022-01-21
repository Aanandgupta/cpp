#include <bits/stdc++.h>
using namespace std;


class node{
    public:
        int data;
        node* next;

        node(int data)
        {
            this->data=data;
            next=NULL;
        }
        

        void insertAtHead(node * &head,int data)
        {
            node *temp=new node(data);
            if(head==NULL)
            {
                head=temp;
                return ;
            }
            temp->next=head;
            head=temp;
            return;

        }


};


int main()
{
    return 0;
}