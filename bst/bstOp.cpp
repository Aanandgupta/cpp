#include <bits/stdc++.h>
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


int height(bst *head)
{
    if(head==NULL)
    {
        return -1;
    }

    return max(height(head->left),height(head->right))+1; 
}

void insert(bst * &head,int data)
{
    bst *temp=new bst(data);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    bst *head1=head;
    bst *prev=head;
    while(head1!=NULL)
    {
        prev=head1;
        if(head1->data>data)
        {
            head1=head1->left;
        }
        else{
            head1=head1->right;
        }
    }

      if(prev->data > data)
        {
            prev->left=temp;
        }
        else{
            prev->right=temp;
        }
}


void printBfs(bst *head)
{
    queue <bst *> h1;

    if(head==NULL)
        return ;
    h1.push(head);

    while(!h1.empty())
    {
        bst *temp=h1.front();
        cout << temp->data << " ";
        if(temp->left!=NULL)
        h1.push(temp->left);
        if(temp->right!=NULL)
        h1.push(temp->right);
        h1.pop();
    }
    return ;
}

void print(bst *head)
{
    if(head==NULL)
    {
        return ;
    }
    print(head->left);
    cout << head->data << " ";
    print(head->right);
    return ;
}

bool check(bst *head)
{
    if(head==NULL)
    {
        return true;
    }
    bool ans=true;
    if(head->left!=NULL)
    {
        ans&=(head->left->data < head->data); 
        ans&=check(head->left);
    }
    if(head->right!=NULL)
    {
        ans&=(head->right->data >= head->data); 
        ans&=check(head->right);
    }
    return ans;
}


// void remove(bst *head,int data)
// {   
//     if(head==NULL)
//     return ;
//     if(data==head->data)
//     {
        
//     }
//     if(data < head->data)
//     {
//         remove(head->left);
//     }



// }

int main()
{
    bst *head=NULL;
    insert(head,2);
    insert(head,22);
    insert(head,21);
    insert(head,21);
    insert(head,12);
    insert(head,32);
    printBfs(head);
    cout << (head);
    return 0;
}