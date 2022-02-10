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

struct Node* SortedMerge(struct Node* a, struct Node* b)
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