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
};
class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        struct node*prev=NULL,*cur=head,*temp;
        int i=0;
        while(cur!=NULL && i<k)
        {
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
            i++;
        }
        head->next=reverse(cur,k);
        return prev;
    }
};
