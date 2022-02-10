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
class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node* SortedMerge( Node* a,  Node* b)
    {
        if(a==NULL)
        {
            return b;
        }
        if(b==NULL)
        {
            return a;
        }
        if(a->data < b->data)
        {
            a->next=SortedMerge(a->next,b);
            return a;
        }
        else{
            b->next=SortedMerge(a,b->next);
            return b;
        }
        
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL or head->next==NULL)
        {
            return head;
        }
        Node* mid=head,*fast=head->next;
        while(fast !=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            mid=mid->next;
        }
        Node *a=head;
        Node *b=mid->next;
        mid->next=NULL;
        a=mergeSort(a);
        b=mergeSort(b);
        return SortedMerge(a,b);
    }
};
