#include<bits/stdc++.h>
using namespace std;

class bst{
    public:
    int data;
    bst *left;
    bst *right;

    bst(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};



pair <int,int> maxSubset(bst *head)
{
    if(head==NULL)
    {
        return {0,0};
    }
    pair<int,int> a,b;
    int inc,exc;
    a=maxSubset(head->left);
    b=maxSubset(head->right);
    inc=head->data+a.second+b.second;
    exc=max(a.first,a.second)+ max(b.first,b.second);
    return {inc,exc};
}

bst * preOrder()
{
    int a;
    cin >> a;
    if(a==-1)
    {
        return NULL;
    } 
    bst *temp=new bst(a);
    
    temp->left=preOrder();
    temp->right=preOrder();
    return temp;
}

bst * levelOrder()
{
    queue <bst *> store;
    int a,b;
    cin >> a;
    if(a==-1)
    return NULL;
    bst *head=new bst(a);
    store.push(head);
    store.push(NULL);

    while(!store.empty())
    {
        bst *temp1=store.front();
        cin >> a >>b;
        if(a!=-1)
        {
            temp1->left=new bst(a);
            store.push(temp1->left);

        }
        if(b!=-1)
        {
            temp1->right=new bst(b);
            store.push(temp1->right);
        }
        store.pop();
    }
        

    return head;

}


int main()
{
    bst *head;

    return 0;
}