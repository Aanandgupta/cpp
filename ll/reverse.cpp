
#include<bits/stdc++.h>
using namespace std;

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