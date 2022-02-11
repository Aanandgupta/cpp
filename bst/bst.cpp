/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;


class bst{
    public:
    int data;
    bst *right;
    bst *left;
    bst(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

void print(bst *head)
{
    if(head==NULL)
    {
        return ;
    }
    cout << head->data << " ";
    print(head->left);
    print(head->right);
}

bst* preOrder() 
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


void levelOrderBuild(bst * &head)
{
    int a,b;
    queue <bst *> store;
    cin >> a;
    bst *temp;
    if(a!=-1)
    {
        temp=new bst(a);
    }
    else{
        temp=NULL;
    }
    if(head==NULL)
    {
        head=temp;
        store.push(temp);
    }
    while(!store.empty())
    {
        cin >> a>>b;
        bst *temp1=store.front();
        if(a!=-1)
        {
            temp=new bst(a);
            temp1->left=temp;
            store.push(temp);
        }
        if(b!=-1)
        {
            temp=new bst(b);
            temp1->right=temp;
            store.push(temp);
        }
        
        store.pop();
    
    }
    return;


}




int main()
{
    // bst *head=preOrder();
    bst *head=NULL;
    levelOrderBuild(head);
    print(head);
    return 0;
}