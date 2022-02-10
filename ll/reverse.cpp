
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data=data;
            next=NULL;
        }
};

struct Node* reverseList(struct Node *head)
    {
        if(head==NULL)
        {
            return NULL;
        }
        struct Node *cur=head,*temp,*prev=NULL;
        
        while(cur!=NULL)
        {
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
        
    }




    ///recursive
    

struct Node* reverseList(struct Node * head)
    {
        if(head->next==NULL || head==NULL)
        {
            return head;
        }
        struct Node *temp=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
        
    }
